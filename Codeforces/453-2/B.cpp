#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
int c[N], p[N];

int main() {
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i) scanf("%d", p + i);
  for(int i = 1; i <= n; ++i) scanf("%d", c + i);
  int ans = 1;
  for(int i = 2; i <= n; ++i) ans += (c[i] != c[p[i]]);
  printf("%d\n", ans);
  return 0;
}