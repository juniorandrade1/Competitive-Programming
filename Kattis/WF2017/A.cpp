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

const int N = 210;

#define Pi acos(-1.0)
#define eps 1e-9

inline double cmp(double a, double b) {
  if(fabs(a - b) <= eps) return 0.0;
  return b - a;
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
  double operator * (Point q) { return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
  double operator % (Point q) { return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
  Point operator * (double p) { return Point(x * p, y * p); }
  double polar() { return ((y > -eps) ? atan2(y,x) : 2*Pi + atan2(y,x)); }
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

struct Line {
  double a, b, c;
  Line(){};
  Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  Line(Point s, Point t) {
    a = t.y - s.y;
    b = s.x - t.x;
    c = -a * s.x - b * s.y;
  }
  bool parallel(Line other) { return fabs(a * other.b - b * other.a) < eps; }
  Point intersect(Line other) {
    if(this->parallel(other)) return Point(-HUGE_VAL, -HUGE_VAL);
    else {
      double determinant = this->b * other.a - this->a * other.b;
      double x = (this->c * other.b - this->b * other.c) / determinant;
      double y = (this->a * other.c - this->c * other.a) / determinant;
      return Point(x, y);
    }
  }
  Line perpendicular(Point Point) {
    return Line(-b, a, b * Point.x - a * Point.y);
  }
  double distance(Point r) {
    Point p, q;
    if(fabs(b) < eps) {
      p = Point(-c / a, 0);
      q = Point((-c - b) / a, 1);
    }
    else {
      p = Point(0, -c / b);
      q = Point(1, (-c - a) / b);
    }
    Point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    return fabs(A % B) / sqrt(c);
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
    static double segDistance(Point p, Point q, Point r) {
      Point A = r - q, B = r - p, C = q - p;
      double a = A * A, b = B * B, c = C * C;
      if (cmp(b, a + c) >= 0) return sqrt(a);
      else if (cmp(a, b + c) >= 0) return sqrt(b);
      else return fabs(A % B) / sqrt(c);
    }
    static bool insideSegment(Point s, Point t, Point p) {
      double dst = s.distance(t);
      double dsp = s.distance(p);
      double dpt = p.distance(t);
      return fabs(dst - dsp - dpt) < eps;
    }

};

int n;
Point p[N];
Point pivot;

bool ordByRandomPivot(Point a, Point b) {
  Point oa = a - pivot;
  Point ob = b - pivot;
  return atan2(oa.y, oa.x) < atan2(ob.y, ob.x);
}

inline bool PointInPolygon(Point q) {
  for(int i = 0; i < n; ++i) {
    if(fabs((q - p[i]) % (p[i + 1] - p[i])) > eps) continue;
    if((q - p[i]) * (p[i + 1] - p[i]) < -eps) continue;
    if((q - p[i + 1]) * (p[i] - p[i + 1]) < -eps) continue;
    return true;
  }
  bool ok = 0;
  for(int i = 0; i < n; ++i) {
    Point a = p[i], b = p[i + 1];
    if(fabs(a.x - b.x) < eps) continue;
    if(a.x > b.x) swap(a, b);
    if(q.x < a.x - eps) continue;
    if(q.x > b.x - eps) continue;
    if((q - a) % (b - a) > 0) ok ^= 1;
  }
  return ok;
}


bool intersect(Point p, Point q, Point a, Point b, Point &sol) {
  double na = (a - p) % (q - p), nb = (b - p) % (q - p);
  if(na * nb > eps) return false;
  if(fabs(na - nb) < eps) return false;
  sol = (a + (b - a) * (na / (na - nb)));
  return true;
}

double solve(Point a, Point b) {
  pivot = Point(1000000000.,1000000000.);
  vector< Point > mySet;
  for(int i = 0; i < n; ++i) {
    Point g;
    if(intersect(a, b, p[i], p[i + 1], g)) mySet.pb(g);
  }
  sort(mySet.begin(), mySet.end());
  double ans = 0;
  Point prev = mySet[0];
  for(int i = 0; i + 1 < mySet.size(); i++) {
    Point s = mySet[i] + (mySet[i + 1] - mySet[i]) * 0.5;
    if(!PointInPolygon(s)) prev = mySet[i + 1];
    ans = max(ans, prev.distance(mySet[i + 1]));
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  p[n] = p[0];
  double ans = 0;
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) ans = max(ans, solve(p[i], p[j]));
  printf("%.10lf\n", ans);
  return 0;
}