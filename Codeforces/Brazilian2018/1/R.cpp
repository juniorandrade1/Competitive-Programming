#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
  if(a == b && b == c && c == 0) {
    puts("-1");
    return 0;
  }
  ll delta = b * b - (4.0 * a * c);
  if(delta < 0) printf("0\n");
  else if(delta == 0) {
    printf("1\n");
    long double sol = (1. * -b) / (2. * a);
    printf("%.10lf\n", (double)sol);
  }
  else {
    printf("2\n");
    long double s0 = ((long double)-b + sqrt(delta)) / (2.0 * (long double)a);
    long double s1 = ((long double)-b - sqrt(delta)) / (2.0 * (long double)a);
    if(s0 > s1) swap(s0, s1);
    printf("%.10lf\n%.10lf\n", (double)s0, (double)s1);
  }
  return 0;
}