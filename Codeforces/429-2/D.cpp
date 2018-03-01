#include <bits/stdc++.h>

using namespace std;

typedef vector< pair<int, int> > vii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef pair<int, int>ii;

const int N = 300030;


int n, m;
int d[N];
vii g[N];
int vis[N][2];

int dfs(int x, int op) {
  if(vis[x][op] != -1) return vis[x][op];
  int ax[4];
  memset(ax, 0, sizeof ax);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].F;
    int l = 0;
    if(dfs(y, op ^ 1)) l |= 1;
    if(dfs(y, op)) l |= 2;
    ax[l]++;
  }
  if(ax[0]) return vis[x][op] =  false;
  if(d[x] == -1) return vis[x][op] = true;
  if(d[x] == op && (ax[1] % 2 == 0)) return vis[x][op] = true;
  if(d[x] != op && (ax[1] % 2 == 1)) return vis[x][op] = true;
  return vis[x][op] = false;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", d + i);
  }
  set<int>sol;
  for(int i = 1; i <= m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    if(x == y) {
      sol.insert(i);
      continue;
    }
    g[x].pb(mp(y, i));
    g[y].pb(mp(x, i));
  }
  memset(vis, -1, sizeof vis);
  int ok = 1;
  for(int i = 1; i <= n && ok; ++i) {
    ok &= dfs(i, 0);
  }
  if(!ok) puts("-1");
  else {
    puts("OK");
  }
  return 0;
}