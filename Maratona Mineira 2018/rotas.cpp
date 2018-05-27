//Rotas

#include <bits/stdc++.h>

#pragma comment(linker, '/STACK:200000')

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

const int N = 301;

struct Edge {
  int x, y;
  double c, b;
  Edge() {

  }
  Edge(int _x, int _y, double _c, double _b) {
    x = _x;
    y = _y;
    c = _c;
    b = _b;
  }
};

int n, m;
vector< Edge > e;
double dis[N];
vector< pair<int, double> > g[N];

inline bool hasNegativeCycle(double value) {
  for(int x = 0; x < n; ++x) {
    g[x].clear();
    dis[x] = 0;
  }
  for(int i = 0; i < (int)e.size(); ++i) {
    double w = e[i].c - value * e[i].b;
    g[e[i].x].pb(mp(e[i].y, w));
  }
  for(int z = 0; z < n; ++z) {
    for(int x = 0; x < n; ++x) {
      for(int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].F;
        double w = g[x][i].S;
        if(dis[y] > dis[x] + w) {
          dis[y] = dis[x] + w;
        }
      }
    }
  }
  for(int x = 0; x < n; ++x) {
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      double w = g[x][i].S;
      if(dis[y] > dis[x] + w) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int u, v, c, b;
    scanf("%d %d %d %d", &u, &v, &c, &b); u--; v--;
    e.pb(Edge(u, v, c, b));
  }
  double lo = 0, hi = 10000000000.0;
  for(int i = 0; i < 100; ++i) {
    double md = (lo + hi) * 0.5;
    if(!hasNegativeCycle(md)) lo = md;
    else hi = md;
  }
  printf("%.10lf\n", lo);
  return 0;
}
