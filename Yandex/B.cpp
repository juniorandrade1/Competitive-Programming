#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;
int a[2 * N][N];
int g[N * 2][N * 2];

inline int hasConnection(int x, int y) {
  if(x == y) return -1;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[x][i] == a[y][j]) return i;
    }
  }
  return -1;
}

int vis[N];

void go(int x, int ult, int op) {
  if(vis[x] == 1) return;
  vis[x] = 1;
  if(op == 0) {
    for(int i = 0; i < n; ++i) printf("%d ", a[x][i]);
  }
  for(int i = 0; i < 2 * n; ++i) {
    if(i == x) continue;
    if(i == ult) continue;
    if(g[x][i] == -1) continue;
    go(i, x, op ^ 1);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 2 * n; ++i) {
    for(int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
  }
  for(int i = 0; i < 2 * n; ++i) {
    for(int j = 0; j < 2 * n; ++j) {
      g[i][j] = hasConnection(i, j);
    }
  }
  go(0, 0, 0);
  
  return 0;
}