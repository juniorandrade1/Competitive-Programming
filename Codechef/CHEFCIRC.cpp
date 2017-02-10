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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define eps 1e-6

const int N = 505;

int cmp(double d) {
  return (d > eps) - (d < eps); 
}

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lf %lf", &x, &y); }
  double distance(Point other) { return hypot(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
};

Point p[N];
int n, m;
vector< pair<double, int> > lineSweep;

inline bool ok(double r) {
  for(int i = 0; i < n; ++i) {
    lineSweep.clear();
    for(int j = 0; j < n; ++j) {
      if(p[i].distance(p[j]) > 2 * r) continue;
      if(i == j) continue;
      double dx = (p[j].x - p[i].x);
      double dy = (p[j].y - p[i].y);
      double ang = atan2(dy, dx);
      double d = p[i].distance(p[j]) * 0.5;
      double gap = acos(d / r);
      double aL = ang - gap;
      while(cmp(aL) < 0) aL += 2 * PI;
      while(cmp(aL - 2 * PI) > 0) aL -= 2 * PI;
      double aR = ang + gap;
      while(cmp(aR) < 0) aR += 2 * PI;
      while(cmp(aR - 2 * PI) > 0) aR -= 2 * PI;
      if (cmp(aL - aR) > 0) {
        lineSweep.pb(mp(0, -1));
        lineSweep.pb(mp(aR, 1));
        lineSweep.pb(mp(aL, -1));
        lineSweep.pb(mp(2.0 * PI, 1));
      } else {
        lineSweep.pb(mp(aL, -1));
        lineSweep.pb(mp(aR, 1));
      }
    }
    sort(lineSweep.begin(), lineSweep.end());
    int qtd = 0;
    for(int j = 0; j < lineSweep.size(); ++j) {
      qtd -= lineSweep[j].S;
      if(qtd == m - 1) return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) p[i].read();
  if(m == 1) {
    puts("0.000000");
    return 0;
  }
  double lo = 0, hi = 100000.;
  for(int i = 0; i < 40; ++i) {
    double mid = (lo + hi) * 0.5;
    if(ok(mid)) hi = mid;
    else lo = mid;
  }
  printf("%.6lf\n", lo);
  return 0;
}