#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  double ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    if(x == 0) ans += 2;
    else ans += 1. / (double)x;
  }
  printf("%.10lf\n", ans);
  return 0;
}