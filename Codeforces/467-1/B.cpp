#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

void dfs(vector< vector< int > > &g, vector< vector< int > > &vis, int x, int pr, int &win, int &draw, vector< int > &sol) {
  if(vis[x][pr] == 2) return;
  if(vis[x][pr] == 1) {
    draw = 1;
    return;
  }
  sol.push_back(x);
  if(g[x].size() == 0 && pr == 1) {
    win = 1;
    return;
  }
  vis[x][pr] = 1;
  for(int i = 0; i < g[x].size() && !win; ++i) {
    int y = g[x][i];
    dfs(g, vis, y, pr ^ 1, win, draw, sol);
  }
  vis[x][pr] = 2;
  if(win) return;
  sol.pop_back();
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  vector< vector< int > > g(n + 1);
  vector< vector< int > > vis(n + 1); 
  for(int i = 1; i <= n; ++i) {
    int c; scanf("%d", &c);
    vis[i].resize(2);
    for(int j = 0; j < c; ++j) {
      int x; scanf("%d", &x);
      g[i].push_back(x);
    }
  } 
  int s; scanf("%d", &s);
  int win = 0, draw = 0;
  vector< int > sol;
  dfs(g, vis, s, 0, win, draw, sol);
  if(win) {
    puts("Win");
    for(int i = 0; i < sol.size(); ++i) {
      printf("%d ", sol[i]);
    }
    printf("\n");
  }
  else if(draw) {
    puts("Draw");
  }
  else {
    puts("Lose"); 
  }
  return 0;
}