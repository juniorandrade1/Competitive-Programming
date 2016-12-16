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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 2010;

int n, m;

struct est {
  int y, s, d;
  est(){};
  est(int _y, int _d, int _s) {
    y = _y;
    s = _s;
    d = _d;
  }
};

vector< est > g[N];
ll dis[N];

ll dij(int level) {
  for(int i = 0; i < n; ++i) dis[i] = LINF;
  dis[0] = 0;
  pq<ii>q; q.push(ii(0, 0));
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.S;
    ll w = -foo.F;
    if(dis[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      if(g[x][i].s > level) continue;
      if(dis[g[x][i].y] > dis[x] + g[x][i].d) {
        dis[g[x][i].y] = dis[x] + g[x][i].d;
        q.push(mp(-dis[g[x][i].y], g[x][i].y));
      }
    }
  }
  return dis[n - 1];
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--;
    g[a].pb(est(b, c, d));
    g[b].pb(est(a, c, d));
  }
  int T; scanf("%d", &T);
  int lo = 0, hi = 1000000;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(dij(mid) <= T) hi = mid;
    else lo = mid + 1;
  }
  ll foo = dij(lo);
  if(foo > T) puts("NO");
  else {
    printf("YES\n%d %lld\n", lo, foo);
  }
  return 0;
}