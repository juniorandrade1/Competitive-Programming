#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);


int main() {
  double d, D, V;
  scanf("%lf %lf", &D, &V);
  d = (3 * V - D * D * D) * 0.5;
  printf("%.10lf\n", d);
  printf("%.3lf\n", pow(d, 1.0 / 3.0));
  return 0;
}