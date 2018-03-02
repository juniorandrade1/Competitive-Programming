#include <bits/stdc++.h>

using namespace std;

#define debug(x...) fprintf(stderr, x)

int main() {
  long long k, p, x;
  scanf("%lld %lld %lld", &k, &p, &x);
  long double ans = HUGE_VAL;
  for(int i = 1; i <= 1000000; ++i) {
    long double d = (k * p * 1.0) / (double)i;
    ans = min(ans, d + x * i);
  }
  printf("%.3lf\n", (double)ans);
  return 0;
}