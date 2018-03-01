#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pi acos(-1.0)

const int M = 11;
const int N = (1 << M);
const int SQ = 1;

int n;
ll v[N];
ll x[N], y[N];

ll ldp[N];
ll dp[N], pdp[N];
int memo[N];
ll ans[N];
bitset< N > vis;

void dfs(int x, ll val) {
  if(vis[x]) return;
  dp[x] += val;
  vis[x] = 1;
  int ax = x;
  while(ax) {
    int b = LSONE(ax);
    dp[(x ^ b)] += dp[x];
    dfs(x ^ b, val);
    ax -= b;
  }
}

inline void go(int l, int r, int sm) {
  memcpy(pdp, dp, sizeof dp);
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < N; ++i) {
    vis.reset();
    dfs(i, pdp[i]);
  }
  vector< int > s;
  for(int i = 0; i < n; ++i) if(v[i] - ldp[i] > 0 && v[i] - dp[i] <= 0) s.pb(i);
  for(int i = 0; i < s.size(); ++i) {
    int id = s[i];
    ll c = 0;
    for(int j = l; j <= r; ++j) {
      c += ((x[j] & id) == id) ? y[j] : 0;
      if(v[id] - ldp[id] - c <= 0) {
        ans[j]--;
        break;
      }
    }
  }
  for(int i = 0; i < (1 << M); ++i) ldp[i] += dp[i], dp[i] = 0;
}
 
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  int q; scanf("%d", &q);
  int lst = 1;
  for(int i = 1; i <= q; ++i) {
    scanf("%lld %lld", x + i, y + i);
    x[i] &= ((1 << M) - 1);
    dp[x[i]] += y[i];
    if(i % SQ == 0) {
      go(lst, i, i / SQ);
      lst = i + 1;
    }
  }
  if(lst <= q) go(lst, q, n + 1);
  ans[0] = n;
  for(int i = 1; i <= q; ++i) ans[i] += ans[i - 1], printf("%lld\n", ans[i]);
  return 0;
} 