#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int n;
double v[N];
double c, d, s;

inline void main2(int test) {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lf", v + i);
  scanf("%lf %lf %lf", &c, &d, &s);
  double ans = (*max_element(v, v + n)) * (c - 1);
  printf("%.10lf\n", ans);
  return;
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}