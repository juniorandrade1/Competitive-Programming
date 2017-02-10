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

const int N = 300;

int n, m, w;
int mP[N][N], mW[N][N];
vi g[N];
int match[N], vis[N];

int dfs(int x) {
  if(vis[x]) return 0;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(match[y] == -1 || dfs(match[y])) {
      match[y] = x;
      return 1;
    }
  }
  return 0;
}

void addEdge(int x, int y) {
  g[x].pb(y);
}

inline void main2() {
  memset(mP, 0, sizeof mP);
  memset(mW, 0, sizeof mW);
  scanf("%d %d %d", &n, &m, &w);
  for(int i = 0; i < n; ++i) {
    g[i].clear();
    int y; scanf("%d", &y);
    while(y--) {
      int x; scanf("%d", &x);
      mP[i][x - 1] = 1;
    }
  }
  for(int i = 0; i < n; ++i) {
    int y; scanf("%d", &y);
    while(y--) {
      int x; scanf("%d", &x);
      mW[i][x - 1] = 1;
    }
  }
  for(int i = 0; i < m; ++i) {
    int y; scanf("%d", &y);
    while(y--) {
      int x; scanf("%d", &x); x--;
      for(int j = 0; j < n; ++j) if(mP[j][i] && mW[j][x]) addEdge(j, i);
    }
  }
  int f = 0;
  memset(match, -1, sizeof match);
  for(int i = 0; i < n; ++i) {
    memset(vis, 0, sizeof vis);
    f += dfs(i);
  }
  printf("%d\n", f);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}