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

const int N = 110;

int n, m;
vii g[N][2];
ii dis[N];

inline ii dij(int st, int ed) {
  for(int i = 0; i < n; ++i) dis[i] = ii(INF, INF);
  dis[st] = ii(0, 0);
  pq< pair<ii, int> > q; q.push(mp(dis[st], st));
  while(!q.empty()) {
    pair<ii, int> foo = q.top(); q.pop();
    int x = foo.S;
    ii other = ii(-foo.F.F, -foo.F.S);
    if(dis[x] != other) continue;
    for(int z = 0; z < 2; ++z) {
      for(int i = 0; i < g[x][z].size(); ++i) {
        ii at = g[x][z][i];
        int y = at.F, w = at.S;
        ii nd = dis[x];
        if(z == 0) nd.F += w;
        else nd.S += w;
        if(dis[y] > nd) {
          dis[y] = nd;
          q.push(mp(mp(-dis[y].F, -dis[y].S), y));
        }
      }
    }
  }
  return dis[ed];
}

inline void main2() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) g[i][0].clear(), g[i][1].clear();
  for(int i = 0; i < m; ++i) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; d--;
    g[a][d].pb(mp(b, c));
    g[b][d].pb(mp(a, c));
  }
  int st, ed; scanf("%d %d", &st, &ed); st--; ed--;
  ii sol = dij(st, ed);
  if(sol == ii(INF, INF)) puts("-1");
  else printf("%lld %lld\n", sol.F, sol.F + sol.S);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}