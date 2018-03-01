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
#define pi acos(-1.0)
#define eps 1e-6



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
  Line perpendicular(Point point) {
    return Line(-b, a, b * point.x - a * point.y);
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

struct geometric_utils {
  double cross(Point a, Point b, Point c) {
    double dx1 = (a.x-b.x), dy1 = (a.y-b.y);
    double dx2 = (c.x-b.x), dy2 = (c.y-b.y);
    return (dx1 * dy2 - dx2 * dy1);
  }
  bool above(Point a, Point b, Point c) {
    return cross(a, b, c) >= 0;
  }
  bool under(Point a, Point b, Point c) {
    return cross(a, b, c) <= 0;
  }
  bool sameLine(Point a, Point b, Point c) {
    return cross(a, b, c) < eps;
  }
}
GeometricUtils;

vector< Point > ConvexHull(vector< Point > &polygon) {
  sort(polygon.begin(), polygon.end());
  vector< Point > down, up;
  up.pb(polygon[0]);
  up.pb(polygon[1]);
  down.pb(polygon[0]);
  down.pb(polygon[1]);
  for(int i = 2; i < polygon.size(); ++i) {
    while(up.size() >= 2 && GeometricUtils.above(up[up.size() - 2], up[up.size() - 1], polygon[i])) up.pop_back();
    while(down.size() >= 2 && GeometricUtils.under(down[down.size() - 2], down[down.size() - 1], polygon[i])) down.pop_back();
    up.pb(polygon[i]);
    down.pb(polygon[i]);
  }
  vector< Point > sol = up;
  for(int i = down.size() - 2; i > 0; --i) sol.pb(down[i]);
  return sol;
}


const int N = 101;

int n;
vector< Point > poly;

inline void main2() {
  poly.clear();
  for(int i = 0; i < n; ++i) {
    Point p; p.read();
    poly.pb(p);
  }
  vector< Point > ch = ConvexHull(poly);
  double ans = HUGE_VAL;
  n = ch.size();
  int j = 1;
  for(int i = 0; i < n; ++i) {
    Line l = Line(ch[i], ch[(i + 1) % n]);
    while(l.distance(ch[j]) < l.distance(ch[(j + 1) % n])) j++, j %= n;
    ans = min(ans, l.distance(ch[j]));
  }
  printf("%.2lf\n", ans + 0.005);
}

int main() {
  int test = 1;
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;
    printf("Case %d: ", test++);
    main2();
  }
  return 0;
}