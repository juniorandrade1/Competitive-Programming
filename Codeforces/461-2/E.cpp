#include <bits/stdc++.h>

using namespace std;

#define LINF 0x3f3f3f3f3f3f3f3f

typedef long long ll;

const int N = 1001;
const int M = 20001;

ll pd[2][M];
ll c[N], cost[N];
ll n, w, b, x;

int main() {
  scanf("%lld %lld %lld %lld", &n, &w, &b, &x);
  for(int i = 1; i <= n; ++i) scanf("%lld", c + i);
  for(int i = 1; i <= n; ++i) scanf("%lld", cost + i);
  for(int i = 0; i < 2; ++i) for(int j = 0; j < M; ++j) pd[i][j] = -LINF;
  pd[0][0] = w;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < M; ++j) pd[i & 1][j] = -LINF;
    for(int j = 0; j < M; ++j) {
      ll totCost = 0;
      for(int k = 0; k <= c[i]; ++k) {
        if(pd[~i & 1][j] < totCost) break;
        pd[i & 1][j + k] = max(pd[i & 1][j + k], pd[~i & 1][j] - cost[i] * k);
        totCost += cost[i];
      }
    }
    for(int j = 0; j < M; ++j) if(pd[i & 1][j] >= 0) pd[i & 1][j] = min(pd[i & 1][j] + x, b * j + w);
  }
  int sol = 0;
  for(int i = 0; i < M; ++i) if(pd[n & 1][i] >= 0) sol = max(sol, i);
  printf("%d\n", sol);
  return 0;
}
