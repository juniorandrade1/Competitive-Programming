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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1e5 + 10;

#define pi acos(-1.0)
#define eps 1e-6

inline bool cmp(double a, double b) {
  if(fabs(a - b) < eps) return 0;
  return a - b;
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
  Point operator / (double t) { return Point(x / t, y / t); }
  double operator * (Point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
  double operator % (Point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
  double polar() { return ((y > -eps) ? atan2(y,x) : 2*pi + atan2(y,x)); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
};

class GeometricUtils {
  public:
    GeometricUtils(){};
    static double cross(Point a, Point b, Point c) {
      double dx1 = (a.x - b.x), dy1 = (a.y - b.y);
      double dx2 = (c.x - b.x), dy2 = (c.y - b.y);
      return (dx1 * dy2 - dx2 * dy1);
    }
    static bool above(Point a, Point b, Point c) {
      return cross(a, b, c) < 0;
    }
    static bool under(Point a, Point b, Point c) {
      return cross(a, b, c) > 0;
    }
    static bool sameLine(Point a, Point b, Point c) {
      return cross(a, b, c) < eps;
    }
    static double segDistance(Point s, Point p, Point t) { //segment(s->t) to point p
      return cross(s, p, t) / s.distance(t);
    }
};

int n;
Point p[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  double ans = HUGE_VAL;
  for(int i = 0; i < n; ++i) ans = min(ans, GeometricUtils::segDistance(p[i], p[(i + 1) % n], p[(i + 2) % n]));
  printf("%.10lf\n", ans * 0.5);
  return 0;
}