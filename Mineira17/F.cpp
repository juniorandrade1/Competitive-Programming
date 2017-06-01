#include <bits/stdc++.h>

using namespace std;

#define Pi acos(-1.0)
#define eps 1e-9

inline double degToRad(double x) {
  return (x * Pi) / 180.;
}

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read() { scanf("%lf %lf", &x, &y); }
  Point operator + (double t) { return Point(x + t, y + t); }
  Point operator * (double t) { return Point(x * t, y * t); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  double operator % (Point other) { return x * other.y - y * other.x; }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
};

int n, m;
Point s, t;
Point p[10];

bool SegmentIntersect(Point p, Point q, Point a, Point b, Point &sol) {
  double na = (a - p) % (q - p), nb = (b - p) % (q - p);
  if(na * nb > eps) return false;
  if(fabs(na - nb) < eps) return false; 
  sol = (a + (b - a) * (na / (na - nb))); 
  return true;
}

double solve() {
  Point medS = s + (t - s) * 0.5;
  Point medT = t.rotateAroundPoint(degToRad(90), medS);
  Point medVec = medT - medS;
  Point st = medS + medVec * 1e7;
  Point ed = medS - medVec * 1e7;
  vector< Point > poly;
  bool ok = true;
  for(int i = 0; i < 4; ++i) {
    if(ok) poly.push_back(p[i]);
    Point o;
    if(SegmentIntersect(st, ed, p[i], p[i + 1], o)) {
      ok ^= 1;
      poly.push_back(o);
    }
  }
  double area = 0;
  for(int i = 1; i + 1 < poly.size(); ++i) area += ((poly[i + 1] - poly[i]) % (poly[i] - poly[0]));
  if(area < 0) return -area * 0.5;
  return area * 0.5;
}

int main() {
  scanf("%d %d", &n, &m);
  s.read();
  t.read();
  p[0] = Point(0, 0);
  p[1] = Point(n, 0);
  p[2] = Point(n, m);
  p[3] = Point(0, m);
  p[4] = p[0];
  double all = (n * m);
  double ans = solve();
  double s1 = ans / all;
  double s2 = 1. - s1;
  printf("%.6lf %.6lf\n", s1, s2);
  return 0;
}