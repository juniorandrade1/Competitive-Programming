#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 2000020;

vi g[N];
ll sz[N];

void dfs(int x, int ult) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
    sz[x] += sz[y];
  }
  if(sz[x] == 0) sz[x] = 1;
}


int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(0, 0);
  ll ans = 0;
  for(int i = 1; i < n; ++i) {
    ans = max(ans, min(sz[0] - sz[i], sz[i]));
  }
  printf("%lld\n", ans);
  return 0;
} 
