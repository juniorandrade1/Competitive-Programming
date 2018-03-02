#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int M = 5001;

#define mp make_pair
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

struct Edge {
  int y, a, b;
  Edge(){};
  Edge(int _y, int _a, int _b) {
    y = _y;
    a = _a;
    b = _b;
  }
};

int n, m, k;
int s, t;
vector< Edge > g[N];
int dis[N];

ll solve(int st, int nxt) {
  priority_queue< ii > q;
  memset(dis, 0, sizeof dis);
  dis[s] = nxt - 1;
  q.push(ii(dis[s], s));
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.second;
    int w = foo.first;
    if(dis[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].y;
      int a = g[x][i].a;
      int b = g[x][i].b;
      if(a > st) continue;
      if(dis[y] < min(dis[x], b)) {
        dis[y] = min(dis[x], b);
        q.push(ii(dis[y], y));
      }
    }
  }
  if(dis[t] >= st) return dis[t] - st + 1;
  return 0;
}

vector< int > ms;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  scanf("%d %d", &s, &t); s--; t--;
  for(int i = 0; i < m; ++i) {
    int x, y, a, b; scanf("%d %d %d %d", &x, &y, &a, &b); x--; y--;
    g[x].push_back(Edge(y, a, b));
    ms.push_back(a);
  }
  sort(ms.begin(), ms.end());
  ms.erase(unique(ms.begin(), ms.end()), ms.end());
  int ans = 0;
  for(int i = 0; i < (int)ms.size(); ++i) {
    int x = ms[i];
    int nxt = (i + 1 < ms.size()) ? ms[i + 1] : k + 1;
    ans += solve(x, nxt);
  }
  printf("%d\n", ans);
  return 0;
}