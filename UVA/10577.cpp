#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ull;
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
#define snd second
#define pi acos(-1.0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 51;

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
};

struct Circle {
  double x, y, r;
  Circle(){};
  Circle(double _x, double _y, double _r) {
    x = _x;
    y = _y;
    r = _r;
  }
  Circle(Point a, Point b, Point c) {
    Line ab = Line(a, b);
    Line bc = Line(b, c);
    double xAB = (a.x + b.x) * 0.5;
    double yAB = (a.y + b.y) * 0.5;
    double xBC = (b.x + c.x) * 0.5;
    double yBC = (b.y + c.y) * 0.5;
    ab = ab.perpendicular(Point(xAB, yAB));
    bc = bc.perpendicular(Point(xBC, yBC));
    if(ab.parallel(bc)) {
      x = -1;
      y = -1;
      r = -1;
    }
    Point center = ab.intersect(bc);
    x = center.x;
    y = center.y;
    r = center.distance(a);
  }
  double getIntersectionArea(Circle c) {
    double d = hypot(x - c.x, y - c.y);
    if(d >= r + c.r) return 0.0;
    else if (c.r >= d + r) return pi * r * r;
    else if (r >= d + c.r) return pi * c.r * c.r;
    else {
      double a1 = 2.*acos((d * d + r * r - c.r * c.r) / (2. * d * r));
      double a2 = 2.*acos((d * d + c.r * c.r - r * r) / (2. * d * c.r));
      double num1 = (ld)a1 / 2. * r * r - r * r * sin(a1) * 0.5;
      double num2 = (ld)a2 / 2. * c.r * c.r - c.r * c.r * sin(a2)*0.5;
      return num1 + num2;
    }
  }
};

Point p[3];
int n;

Point getCircuncenter(Point a, Point b, Point c) {
  Line l1 = Line(a, b);
  double xab = (a.x + b.x) * 0.5, yab = (a.y + b.y) * 0.5;

  Line l2 = Line(b, c);
  double xbc = (b.x + c.x) * 0.5, ybc = (b.y + c.y) * 0.5;

  l1 = l1.perpendicular(Point(xab, yab));
  l2 = l2.perpendicular(Point(xbc, ybc));

  return l1.intersect(l2);
}

int main() {
  int test = 1;
  while(1) {
    scanf("%d", &n);
    if(!n) break;
    for(int i = 0; i < 3; ++i) p[i].read();
    Point c = getCircuncenter(p[0], p[1], p[2]);
    double angle = (2. * pi) / (double)n;
    Point r = p[0];
    double maxX = -HUGE_VAL, minX = HUGE_VAL;
    double maxY = -HUGE_VAL, minY = HUGE_VAL;
    for(int i = 0; i < n; ++i) {
      r = r.rotateAroundPoint(angle, c);
      maxX = max(maxX, r.x);
      maxY = max(maxY, r.y);
      minX = min(minX, r.x);
      minY = min(minY, r.y);
    }
    double area = (maxX - minX) * (maxY - minY);
    printf("Polygon %d: %.3lf\n", test++, area);
  }
  return 0;
}