#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int N = 102;

vector< int > dx, dy;
int n, m;

int dis[N][N];
pair< int, int > lst[N][N];

bool inside(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

void go(int x, int y) {
  if(x == -1 || y == -1) return;
  pair<int, int> foo = lst[x][y];
  go(foo.first, foo.second);
  printf("%d %d\n", x, y);
}

void bfs(int x1, int y1, int x2, int y2) {
  queue< pair< int, int > > que; que.push(make_pair(x1, y1));
  for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) {
    lst[i][j] = make_pair(-1, -1);
    dis[i][j] = INF;
  }
  dis[x1][y1] = 0;
  while(!que.empty()) {
    pair<int, int>foo = que.front(); que.pop();
    int x = foo.first, y = foo.second;
    for(int i = 0; i < 8; ++i){
      int xx = x + dx[i], yy = y + dy[i];
      if(inside(xx, yy) == false) continue;
      if(dis[xx][yy] > dis[x][y] + 1) {
        que.push(make_pair(xx, yy));
        lst[xx][yy] = make_pair(x, y);
        dis[xx][yy] = dis[x][y] + 1;
      }
    }
  }
  if(dis[x2][y2] == INF) printf("-1\n");
  else {
    printf("%d\n", dis[x2][y2]);
    go(x2, y2);
  }
}

// {p, p, q, -q, -p, -p, -q, q}
// {-q, q, p, p, q, -q, -p, -p}

int main() {
  int p, q, x1, y1, x2, y2;
  scanf("%d %d %d %d %d %d %d %d", &n, &m, &p, &q, &x1, &y1, &x2, &y2);
  dx.push_back(p); dy.push_back(-q);
  dx.push_back(p); dy.push_back(q);
  dx.push_back(q); dy.push_back(p);
  dx.push_back(-q); dy.push_back(p);
  dx.push_back(-p); dy.push_back(q);
  dx.push_back(-p); dy.push_back(-q);
  dx.push_back(-q); dy.push_back(-p);
  dx.push_back(q); dy.push_back(-p);
  bfs(x1, y1, x2, y2);
  return 0;
}