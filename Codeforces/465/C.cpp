#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200001;

#define eps 1e-9


int main() {
  double r, x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);
  if(r - hypot(x1 - x2, y1 - y2) > -eps) {
    puts("%.10lf %.10lf %.10lf\n", x1, y1, r);
    return 0;
  }
  

  return 0;
}