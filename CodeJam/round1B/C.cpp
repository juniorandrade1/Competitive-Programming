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

#define eps 1e-7

const int N = 101;

ll g[N][N];
int n, q;
ll e[N], s[N];

ll distanceTraveled[N][N];

inline void preprocess() {
  pq< pair<ll, ii> > q;
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
    scanf("%lld", &g[i][j]);
    if(g[i][j] == -1) g[i][j] = LINF;
    if(i == j) g[i][j] = 0;
    distanceTraveled[i][j] = LINF;
    if(i == j) {
      distanceTraveled[i][j] = 0;
      q.push(mp(0, ii(i, j)));
    }
  }
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  while(!q.empty()) {
    pair<ll, ii> foo = q.top(); q.pop();
    int st = foo.S.F, at = foo.S.S;
    ll atTime = -foo.F;
    if(distanceTraveled[st][at] != atTime) continue;
    ll has = e[st] - distanceTraveled[st][at];
    for(int i = 0; i < n; ++i) {
      if(has < g[at][i]) continue;
      if(distanceTraveled[st][i] > g[at][i] + distanceTraveled[st][at]) {
        distanceTraveled[st][i] = g[at][i] + distanceTraveled[st][at];
        q.push(mp(-distanceTraveled[st][i], mp(st, i)));
      }
    } 
  }
}

double dis[N];

inline void solve(int a, int b) {
  for(int i = 0; i < n; ++i) dis[i] = HUGE_VAL;
  dis[a] = 0; pq< pair<double, int> > q; q.push(mp(0, a));
  while(!q.empty()) {
    pair<double, int> foo = q.top(); q.pop();
    int x = foo.S;
    double atW = -foo.F;
    if(fabs(dis[x] - atW) > eps) continue;
    //for(int h = 0; h < n; ++h) {
      for(int y = 0; y < n; ++y) {
        int h = x;
        if(distanceTraveled[h][x] + g[x][y] > e[h]) continue;
        double timeNeed = distanceTraveled[h][x] / (double)s[h];
        double bstTime = max(timeNeed, dis[x]);
        bstTime += (g[x][y] / (double)s[h]);
        if(dis[y] > bstTime) {
          dis[y] = bstTime;
          q.push(mp(-dis[y], y));
      //  }
      }
    }
  }
  printf(" %.10lf", dis[b]);
}

inline void main2(int _test) {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) {
    scanf("%lld %lld", e + i, s + i);
  }
  preprocess();
  printf("Case #%d:", _test);
  while(q--) {
    int a, b; scanf("%d %d", &a, &b);
    solve(a - 1, b - 1);
  }
  printf("\n");
  
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}