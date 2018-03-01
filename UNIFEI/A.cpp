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

const ll md = 1000000007LL;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}

const int N = 1234567;

int n;
vi g[N];
ll dp[N][2];

ll func(int dad, int i, int lst, int cor) {
  if(g[dad].size() == i) return 1;
  int x = g[dad][i];
  if(x == lst) return func(dad, i + 1, lst, cor);
  if(dp[x][cor] != -1) return dp[x][cor];
  ll ret = 0;
  ret = addMod(ret, mulMod(func(x, 0, dad, 0), func(dad, i + 1, lst, cor)));
  if(cor == 0) ret = addMod(ret, mulMod(func(x, 0, dad, 1), func(dad, i + 1, lst, cor)));
  return dp[x][cor] = ret;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    if(!n) break;
    for(int i = 0; i < n; ++i) g[i].clear(), dp[i][0] = dp[i][1] = -1;
    for(int i = 0; i + 1 < n; ++i) {
      int a, b; scanf("%d %d", &a, &b);
      g[a].pb(b);
      g[b].pb(a);
    }
    ll st = func(0, 0, 0, 0);
    ll sb = func(0, 0, 0, 1);
    printf("%lld\n",  addMod(st, sb));
  }
  return 0;
}