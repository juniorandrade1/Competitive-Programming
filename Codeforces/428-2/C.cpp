#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector<int> g[N];
int n;
int h[N];

double dfs(int x, int ult) {
  int qtd = g[x].size() - (x != 1);
  if(qtd == 0) return h[x];
  double ans = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    h[y] = h[x] + 1;
    ans += (dfs(y, x) / (double)qtd);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  double ans = dfs(1, 1);
  printf("%.10lf\n", ans);
  return 0;
}