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

const int N = 50;

int n, m;
vi g[N];
int numColors;
int color[N];
bool ok;
int vis[N];

vi connect;

inline bool check() {
  for(int i = 0; i < connect.size(); ++i) {
    int x = connect[i];
    if(color[x] == -1) return false;
    for(int j = 0; j < g[x].size(); ++j) if(color[x] == color[g[x][j]]) return false;
  }
  return true;
}

void dfs(int x) {
  for(int c = 1; c <= numColors && !ok; ++c) {
    color[x] = c;
    if(check()) {
      ok = 1;
      return;
    }
    for(int i = 0; i < g[x].size() && !ok; ++i) if(color[g[x][i]] == -1) dfs(g[x][i]);
    color[x] = -1;
  }
}

void go(int x) {
  connect.pb(x);
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(vis[y]) continue;
    go(y);
  }
}

inline void main2() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) g[i].clear();
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  numColors = 1;
  while(1) {
    bool ans = true;
    memset(color, -1, sizeof color);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; ++i) {
      if(vis[i] == 0) {
        connect.clear();
        go(i);
        ok = false;
        dfs(i);
      }
      ans &= ok;
    }
    if(ans) break;
    numColors++;
  }
  printf("%d\n", numColors);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
