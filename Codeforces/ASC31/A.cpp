#include <bits/stdc++.h>

using namespace std;

const int N = 51;
const int M = 1001;

int n, m, s;
int p[M], w[M];
long double ps[M];
short memo[N][M];
long double dp[N][M];

long double func(int qtd, int step) {
  if(qtd <= 0) return 0.0;
  if(qtd > n) return 1.0;
  if(step >= M) return 0.0;
  if(memo[qtd][step]) return dp[qtd][step]
;  long double ret = 0;
  memo[qtd][step] = 1;
  for(int i = 0; i < m; ++i) {
    ret = max(ret, ps[i] * func(qtd + w[i], step + 1) + (1.0 - ps[i]) * func(qtd - 1, step + 1));
  }
  return dp[qtd][step] = ret;
}

int main() {
  freopen("casino.in", "r", stdin);
  freopen("casino.out", "w", stdout);
  scanf("%d %d %d", &n, &m, &s);
  for(int i = 0; i < m; ++i) {
    scanf("%d %d", p + i, w + i);
    ps[i] = (long double)p[i] / (long double)s;
  }
  printf("%.20lf\n", (double)func(n, 0));
  return 0;
}