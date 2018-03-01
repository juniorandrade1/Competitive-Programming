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

#define pi acos(-1.0)
#define Pi acos(-1.0)
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
};

struct Circle {
  double x, y, r;
  Circle(){
    x = 0; y = 0; r = -1;
  };
  Circle(double _x, double _y, double _r) {
    x = _x;
    y = _y;
    r = _r;
  }
  Circle(Point a) {
    x = a.x;
    y = a.y;
    r = 0.0;
  }
  Circle(Point a, Point b) {
    x = (a.x + b.x) * 0.5;
    y = (a.y + b.y) * 0.5;
    r = a.distance(b) * 0.5;
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

Circle getMinCircle(vector< Point > &p) {
  if(p.size() == 0) return Circle();
  if(p.size() == 1) return Circle(p[0]);
  if(p.size() == 2) return Circle(p[0], p[1]);
  return Circle(p[0], p[1], p[2]);
}

Circle getMinEnclosingCircle(vector<Point>& P, int i, vector<Point> R) {
  if (i == P.size() || R.size() == 3) return getMinCircle(R);
  Circle D = getMinEnclosingCircle(P, i + 1, R);
  if (hypot(P[i].x - D.x, P[i].y - D.y) > D.r) {
    R.push_back(P[i]);
    D = getMinEnclosingCircle(P, i + 1, R);
  }
  return D;
}

Circle minidisk(vector<Point>P) {
  if(P.size() == 1) return Circle(P[0].x, P[0].y, 0);
  random_shuffle(P.begin(), P.end());
  return getMinEnclosingCircle(P, 0, vector<Point>());
}


const int N = 100010;

int n;
Point v[N];



vector< Point > all;

int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    v[i].read();
    all.pb(v[i]);
  }
  Circle c = minidisk(all);
  printf("%.10lf %.10lf %.10lf\n", c.x, c.y, c.r);
  return 0;
}