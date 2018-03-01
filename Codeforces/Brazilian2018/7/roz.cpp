#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int N = 1000001;
const int M = 26;

int n;
vector< int > g[M];
int dp[N][2];

inline int getSol(int ca, int cb) {
  int i = 0, j = 0, sz = 1;
  dp[0][0] = 0;
  dp[0][1] = -INF;
  while(i < g[ca].size() && j < g[cb].size()) {
    dp[sz][0] = 0;
    dp[sz][1] = -INF;
    if(g[ca][i] < g[cb][j]) {
      dp[sz][0] = max(dp[sz][0], dp[sz - 1][0] + 1);
      dp[sz][1] = max(dp[sz][1], dp[sz - 1][1] + 1);
      i++;
    }
    else {
      dp[sz][1] = max(dp[sz][1], dp[sz - 1][0] - 1);
      dp[sz][1] = max(dp[sz][1], dp[sz - 1][1] - 1);
      j++;
    }
    sz++;
  }


  while(i < g[ca].size()) {
    dp[sz][0] = 0;
    dp[sz][1] = -INF;
    dp[sz][0] = max(dp[sz][0], dp[sz - 1][0] + 1);
    dp[sz][1] = max(dp[sz][1], dp[sz - 1][1] + 1);
    i++; sz++;
  }

  while(j < g[cb].size()) {
    dp[sz][0] = 0;
    dp[sz][1] = -INF;
    dp[sz][1] = max(dp[sz][1], dp[sz - 1][0] - 1);
    dp[sz][1] = max(dp[sz][1], dp[sz - 1][1] - 1);
    j++; sz++;
  }

  int foo = -INF;
  for(int i = 0; i < sz; ++i) foo = max(foo, dp[i][1]);
  return foo;
}

inline int solve(int a, int b) {
  return max(getSol(a, b), getSol(b, a));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    g[c - 'a'].push_back(i);
  }
  int ans = 0;
  for(int i = 0; i < M; ++i) for(int j = i + 1; j < M; ++j) ans = max(ans, getSol(i, j));
  printf("%d\n", ans);
  return 0;
}