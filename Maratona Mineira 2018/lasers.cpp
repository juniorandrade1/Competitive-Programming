//Lasers

#include <bits/stdc++.h>

#pragma comment(linker, '/STACK:200000')

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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define eps 1e-8
#define PI acos(-1.0)

const int N = (int)1e5 + 10;

struct LineSweep {
  long double x;
  int op;
  LineSweep(){};
  LineSweep(long double _x, int _op) {
    x = _x;
    op = _op;
  }
  bool operator < (LineSweep other) const {
    if(fabs(x - other.x) > eps)  return x < other.x;
    return op < other.op;
  }
};

int n, m;
vector< LineSweep > lp;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    double xi, yi, xf, yf; scanf("%lf %lf %lf %lf", &xi, &yi, &xf, &yf);
    long double fi = atan2(yi, xi);
    long double ff = atan2(yf, xf);
    if(fi < 0) fi += 2 * PI;
    if(ff < 0) ff += 2 * PI;
    if(fi > ff) swap(fi, ff);
    if(ff - fi <= PI) {
      //debug("==> %.10lf %.10lf\n", fi, ff);
      lp.pb(LineSweep(fi, 0));
      lp.pb(LineSweep(ff, 1));
    }
    else {
      //debug("==> %.10lf %.10lf\n", fi, ff);
      lp.pb(LineSweep(0, 0));
      lp.pb(LineSweep(fi, 1));
      lp.pb(LineSweep(ff, 0));
      lp.pb(LineSweep(2 * PI, 1));
    }
  }
  double num = 0;
  sort(lp.begin(), lp.end());
  int q = 0;
  double prev = lp[0].x;
  for(int i = 0; i < lp.size(); ++i) {
    if(q <= m) num += lp[i].x - prev;
    if(!lp[i].op) q++;
    else q--;
    prev = lp[i].x;
  }
  printf("%.5lf\n", (num / (2.0 * PI)));
  return 0;
}