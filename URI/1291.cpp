#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)

double heron(double a, double b, double c) {
  double s = (a + b + c) * 0.5;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double equilateralArea(double x) {
  return x * x * 0.25 * sqrt(3);
}

int main() {
  double x;
  while(scanf("%lf", &x) != EOF) {
    double allArea = x * x;
    double circleArea = pi * x * x;
    double quarterHalf = circleArea * 0.25;
    double c = x * x * (4. - 2 * pi / 3. - sqrt(3));
    double semC = allArea - c;
    double innerArea = 2.0 * quarterHalf - allArea;
    double a = innerArea * 2.0 - semC;
    double b = allArea - a - c;
    printf("%.3lf %.3lf %.3lf\n", a, b, c);
    
  }
  return 0;
}