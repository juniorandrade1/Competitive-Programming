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

const int N = 100010;

int n, p[N];
vector< int > len;
int vis[N];

int dfs(int x) {
  vis[x] = 1;
  if(vis[p[x]]) return 0;
  return dfs(p[x]) + 1;
}

ll quad(ll x) {
  return x * x;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", p + i);
  for(int i = 1; i <= n; ++i) {
    if(vis[i] == 0) {
      len.push_back(1 + dfs(i));
    }
  }
  sort(len.rbegin(), len.rend());
  ll ans = 0;

  if(len.size() == 1) ans = quad(len[0]);
  else {
    ans += quad(len[0] + len[1]);
    for(int i = 2; i < len.size(); ++i) ans += quad(len[i]);
  }
  printf("%lld\n", ans);
  return 0;
}