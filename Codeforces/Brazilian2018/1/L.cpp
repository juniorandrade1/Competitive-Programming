#include <bits/stdc++.h>

using namespace std;

const int N = 111;

#define INF 0x3f3f3f3f

int n, m;
int g[N][N];

int main() {
  scanf("%d %d", &n, &m);
  memset(g, INF, sizeof g);
  for(int i = 0; i < n; ++i) g[i][i] = 0;
  for(int i = 0; i < m; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    g[a][b] = c;
  }
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  double num = 0;
  double den = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == j) continue;
      if(g[i][j] < INF) {
        num += g[i][j];
        den++;
      }
    }
  }
  printf("%.10lf\n", num / den);
  return 0;
}