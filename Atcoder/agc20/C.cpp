#include <bits/stdc++.h>

using namespace std;

const int N = (int)4e6 + 3;

int n;
bitset< N > dp;

int main() {
  scanf("%d", &n);
  int S = 0;
  dp[0] = 1;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    S += x;
    dp |= dp << x;
  }
  S = (S + 1) / 2LL;
  for(int i = S;; ++i) {
    if(dp[i]) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}