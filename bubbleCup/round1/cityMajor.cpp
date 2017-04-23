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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pi acos(-1.0)
#define eps 1e-6

inline int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
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
  Point operator *(double t) { return Point(x * t, y * t); }
  Point operator /(double t) { return Point(x / t, y / t); }
  double operator * (Point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
  double operator % (Point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
  double polar() { return ((y > -eps) ? atan2(y,x) : 2*pi + atan2(y,x)); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
  double mod() { return sqrt(x * x + y * y); }
  double mod2() { return (x * x + y * y); }
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
};

typedef vector<Point> Polygon;

inline double angle(Point p, Point q, Point r) {
  Point u = p - q, v = r - q;
  return atan2(u % v, u * v);
}

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

struct Circle {
  Point c;
  double x, y, r;
  Circle(){};
  Circle(double _x, double _y, double _r) {
    x = _x;
    y = _y;
    c = Point(x, y);
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
  int ccw(Point p, Point q, Point r) {
    return cmp((p - r) % (q - r));
  }


  Point getCircuncenter(Point a, Point b, Point c) {
    Line l1 = Line(a, b);
    double xab = (a.x + b.x) * 0.5, yab = (a.y + b.y) * 0.5;
    Line l2 = Line(b, c);
    double xbc = (b.x + c.x) * 0.5, ybc = (b.y + c.y) * 0.5;
    l1 = l1.perpendicular(Point(xab, yab));
    l2 = l2.perpendicular(Point(xbc, ybc));
    return l1.intersect(l2);
  }

}
GeometricUtils;

double seg_distance(Point p, Point q, Point r) {
  Point A = r - q, B = r - p, C = q - p;
  double a = A * A, b = B * B, c = C * C;
  if (cmp(b, a + c) >= 0) return sqrt(a);
  else if (cmp(a, b + c) >= 0) return sqrt(b);
  else return fabs(A % B) / sqrt(c);
}



//area da intersecao de um triangulo a,b,S.c com circulo S
double area(Point a, Point b, Circle S) {
  double aa=(S.c-a).mod(), bb=(S.c-b).mod(), cc=seg_distance(a, b, S.c);
  if (cmp(aa,S.r) <= 0 && cmp(bb,S.r) <= 0) return 0.5*fabs((a-S.c)%(b-S.c));
  if (cmp(cc,S.r) >= 0) return 0.5*fabs(S.r * S.r * angle(a, S.c, b));
  if (cmp(aa, bb) > 0) {swap(a, b); swap(aa,bb); }
  double A=(a-b).mod2(), B=2*((a-b)*(b-S.c)), C=(b-S.c).mod2()-S.r*S.r;
  double t = ((cmp(B*B-4*A*C)==0)?0.0: sqrt(B*B-4*A*C));
  double x1 = 0.5*(-B-t)/A, x2 = 0.5*(-B+t)/A;
  Point p1 = a*x1 + b*(1-x1), p2 = a*x2 + b*(1-x2);
  if (cmp(aa, S.r) < 0) return area(a, p1, S) + area(p1, b, S);
  return area(a, p2, S) + area(p2, p1, S) + area(p1, b, S);
}

//area da intersecao de poligono(simples qlqr) com circulo S O(n)
double area(Polygon &T, Circle S) {
  double ans=0.0;
  int n = (int)T.size();
  for (int i = 0; i < n; i++)
  ans += (area(T[i], T[(i+1)%n], S) * GeometricUtils.ccw(T[i], T[(i+1)%n], S.c));
  return fabs(ans);
}

int n, p;
Polygon poly;

int main() {
  while(scanf("%d %d", &n, &p) != EOF) {
    poly.clear();
    for(int i = 0; i < n; ++i) {
      Point foo; foo.read(); poly.pb(foo);
    }
    Circle c = Circle(0, 0, 100000000000000.);
    double totArea = area(poly, c);
    double lo = 0, hi = 100000000000000.;
    for(int i = 0; i < 100; ++i) {
      double m = (lo + hi) * 0.5;
      c.r = m;
      double gap = area(poly, c);
      if(gap * 100 < p * totArea) lo = m;
      else hi = m;
    }
    printf("%.2lf\n", lo);
  }
  return 0;
}