#include <bits/stdc++.h>

using namespace std;
 
double gx(double x){
  if(2*x*x-4 < 0) {return -HUGE_VAL;}
  else {double g = sqrt(2*x*x-4);
  return g;}
}
double fx(double x){
  double f = 1/sin(3*x);
  return f;
}
 
int main() {
  double a;
  cin >> a;
  double g = gx(a);
  if(g == -HUGE_VAL){
    printf("A fog(%.2lf) nao pode ser calculada\n", a);
    return 0;
  }
  else{
    double f=fx(g);
    printf("O valor do fog(%.2lf) = %.3lf\n", a, f);
  }
  // your code goes here
  return 0;
}