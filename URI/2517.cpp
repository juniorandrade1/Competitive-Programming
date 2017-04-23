#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif


double a, b, c, xc, yc, xf;

double test(double x) {
  double y = -(x * x) / a - x / b + c;
  return hypot(x - xc, y - yc);
}

int main() {
  while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
    scanf("%lf %lf", &xc, &yc);
    scanf("%lf", &xf);
    double lo = 0, hi = xf;
    for(int i = 0; i < 100; ++i) {
      double q = (hi - lo) / 3.;
      double m1 = lo + q;
      double m2 = hi - q;
      if(test(m1) < test(m2)) hi = m2;
      else lo = m1;
    }
    printf("%.2lf\n", test(lo));
  }
  return 0;
}