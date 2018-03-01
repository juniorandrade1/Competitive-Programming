#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int N = 1234;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, k;
char mat[N][N];
int disSt[N][N], disFs[N][N];

inline bool isInside(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void process(int x0, int y0, int x1, int y1) {
  queue< pair<int, int> > qSt, qFs;
  memset(disSt, INF, sizeof disSt);
  memset(disFs, INF, sizeof disFs);
  disSt[x0][y0] = disFs[x1][y1] = 0;
  qSt.push(make_pair(x0, y0)); qFs.push(make_pair(x1, y1));
  while(!qSt.empty() && !qFs.empty()) {
    pair<int, int> f1 = qSt.front(); qSt.pop();
    int xSt = f1.first, ySt = f1.second;
    for(int i = 0; i < 4; ++i) for(int j = 1; j <= k; ++j) {
      int x = xSt + dx[i] * j, y = ySt + dy[i] * j;
      if(!isInside(x, y)) break;
      if(mat[x][y] == '#') break;
      if(disSt[x][y] > disSt[xSt][ySt] + 1) {
        disSt[x][y] = disSt[xSt][ySt] + 1;
        qSt.push(make_pair(x, y));
        if(disFs[x][y] != INF && disSt[x][y] != INF) return;
        if(x == x1 && y == y1) return;
      }
    }


    pair<int, int> f2 = qFs.front(); qFs.pop();
    int xFs = f2.first, yFs = f2.second;
    for(int i = 0; i < 4; ++i) for(int j = 1; j <= k; ++j) {
      int x = xFs + dx[i] * j, y = yFs + dy[i] * j;
      if(!isInside(x, y)) break;
      if(mat[x][y] == '#') break;
      if(disFs[x][y] > disFs[xFs][yFs] + 1) {
        disFs[x][y] = disFs[xFs][yFs] + 1;
        qFs.push(make_pair(x, y));
        if(disFs[x][y] != INF && disSt[x][y] != INF) return;
        if(x == x0 && y == y0) return;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; ++i) scanf(" %s", mat[i]);
  int x0, y0, x1, y1;
  scanf("%d %d %d %d", &x0, &y0, &x1, &y1); x0--; y0--; x1--; y1--;
  process(x0, y0, x1, y1);
  int sol = INF;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      sol = min(sol, disSt[i][j] + disFs[i][j]);
    }
  }
  if(sol == INF) sol = -1;
  printf("%d\n", sol);
  return 0;
}