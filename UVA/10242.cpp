#include <bits/stdc++.h>

using namespace std;

#define Pi acos(-1.0)
#define eps 1e-6

double degToRad(double x) {
  return (x * Pi) / 180.;
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
  Point operator * (double t) { return Point(x * t, y * t); }
  Point operator / (double t) { return Point(x / t, y / t); }
  double operator * (Point q) {return x * q.x + y * q.y;} 
  double operator % (Point q) {return x * q.y - y * q.x;} 
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
  bool operator == (Point other) const {
    return fabs(x - other.x) < eps && fabs(y - other.y) < eps;
  }
};


int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;
  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF) {
    set< Point > s;
    map< Point, int > qtd;
    int cnt = 1;
    if(qtd[Point(x1, y1)] == 0) qtd[Point(x1, y1)] = cnt++;
    if(qtd[Point(x2, y2)] == 0) qtd[Point(x2, y2)] = cnt++;
    if(qtd[Point(x3, y3)] == 0) qtd[Point(x3, y3)] = cnt++;
    if(qtd[Point(x4, y4)] == 0) qtd[Point(x4, y4)] = cnt++;

    s.insert(Point(x1, y1));
    s.insert(Point(x2, y2));
    s.insert(Point(x3, y3));
    s.insert(Point(x4, y4));
    if(s.size() != 3) assert(true);

    Point p[4];
    p[qtd[*s.begin()]] = *s.begin();
    s.erase(s.begin());
    p[qtd[*s.begin()]] = *s.begin();
    s.erase(s.begin());
    p[qtd[*s.begin()]] = *s.begin();
    s.erase(s.begin());

    Point ac = p[1] + (p[3] - p[1]) * 0.5;
    Point o = p[2].rotateAroundPoint(degToRad(180.), ac);
    if(fabs(o.x) < eps) o.x = 0.0;
    if(fabs(o.y) < eps) o.y = 0.0;
    printf("%.3lf %.3lf\n", o.x, o.y);
  }
  return 0;
}