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

const int N = 1e5 + 10;

int n, m;
vii g[N];
ll d1[N], d2[N];

inline void dij1() {
  for(int i = 0; i < n; ++i) d1[i] = LINF;
  pq<ii>q; q.push(mp(0, 0));
  d1[0] = 0;
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.S;
    ll w = -foo.F;
    if(d1[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll c = g[x][i].S;
      if(d1[y] > d1[x] + c) {
        d1[y] = d1[x] + c;
        q.push(mp(-d1[y], y));
      }
    }
  }
}

inline void dij2() {
  for(int i = 0; i < n; ++i) d2[i] = LINF;
  pq<ii>q; q.push(mp(0, n - 1));
  d2[n - 1] = 0;
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.S;
    ll w = -foo.F;
    if(d2[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll c = g[x][i].S;
      if(d2[y] > d2[x] + c) {
        d2[y] = d2[x] + c;
        q.push(mp(-d2[y], y));
      }
    }
  }
}

int main() {
  double sss = numeric_limits<double>::max();
  printf("%lf\n", log10(sss));

  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }
  dij1();
  dij2();
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < g[i].size(); ++j) {
      int x = i;
      int y = g[i][j].F;
      ll w = g[i][j].S;
      if(d1[x] + d2[y] + w == d1[n - 1] || d1[y] + d2[x] + w == d1[n - 1]) ans += w;
    }
  }
  printf("%lld\n", ans);
  return 0;
}