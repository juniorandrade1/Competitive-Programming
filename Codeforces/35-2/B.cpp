#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int sol = 0;
  for(int i = 1; i < n; ++i) sol = max(sol, min(a / i, b / (n - i)));
  printf("%d\n", sol);
  return 0;
}