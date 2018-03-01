#include <bits/stdc++.h>

using namespace std;

const int N = 501;
const int INF = 0x3f3f3f3f;

int n, m;
int vis[N][N];
int v[N][N];

inline void bfs(int sx, int sy) {
  queue< pair<int, int> > q;
  q.push(make_pair(sx, sy));
  vis[sx][sy] = 1;
  while(!q.empty()) {
    pair<int, int>foo = q.front(); q.pop();
    int x = foo.first, y = foo.second;
    for(int i = -1; i <= 1; ++i) {
      for(int j = -1; j <= 1; ++j) {
	int nx = x + i, ny = y + j;
	if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
	if(vis[nx][ny]) continue;
	if(v[nx][ny] >= 0) continue;
	q.push(make_pair(nx, ny));
	vis[nx][ny] = 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d", &v[i][j]);
  int x, y; scanf("%d %d", &x, &y); x--; y--;
  bfs(x, y);
  long long ans = 0;
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
      if(vis[i][j]) ans += max(v[i][j], v[x][y]);
  }
  printf("%lld\n", -ans);
  return 0;
}
