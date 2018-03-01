#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)

#define eps 1e-9

inline double degToRad(double x) {
  return (x * pi) / 180.0;
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
  double operator * (Point q) {return x * q.x + y * q.y;} //a*b = |a||b|cos(ang) //Positivo se o vetor B está do mesmo lado do vetor perpendicular a A
  double operator % (Point q) {return x * q.y - y * q.x;} //a%b = |a||b|sin(ang) //Angle of vectors
  double polar() { return ((y > -eps) ? atan2(y,x) : 2*pi + atan2(y,x)); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    return (*this - p).rotate(t) + p;
  }
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
  void print() {
    printf("(%.10lf %.10lf)\n", x, y);
  }
};

inline double secondTSearch(Point p, Point c1, double r1, double b1, double e1) {
  double lo = b1, hi = e1;
  for(int i = 0; i < 1000; ++i) {
    double p0 = lo + ((hi - lo) / 3.0);
    double p1 = hi - ((hi - lo) / 3.0);
    Point fstP = c1; fstP.x += r1; fstP = fstP.rotateAroundPoint(p0, c1);
    Point sndP = c1; sndP.x += r1; sndP = sndP.rotateAroundPoint(p1, c1);
    if(p.distance(fstP) < p.distance(sndP)) hi = p1;
    else lo = p0;
  }
  Point sol = c1; sol.x += r1; sol = sol.rotateAroundPoint(lo, c1);
  return p.distance(sol);
}

inline double firstTSearch(Point c0, double r0, double b0, double e0, Point c1, double r1, double b1, double e1) {
  
  double lo = b0, hi = e0;
  for(int i = 0; i < 1000; ++i) {
    double p0 = lo + ((hi - lo) / 3.0);
    double p1 = hi - ((hi - lo) / 3.0);
    Point fstP = c0; fstP.x += r0; fstP = fstP.rotateAroundPoint(p0, c0);
    Point sndP = c0; sndP.x += r0; sndP = sndP.rotateAroundPoint(p1, c0);
    if(secondTSearch(fstP, c1, r1, b1, e1) < secondTSearch(sndP, c1, r1, b1, e1)) hi = p1;
    else lo = p0;
  }
  Point sol = c0; sol.x += r0; sol = sol.rotateAroundPoint(lo, c0);
  return secondTSearch(sol, c1, r1, b1, e1);
  
  /*
  printf("%.10lf %.10lf\n", b0, e0);
  double ans = HUGE_VAL;
  for(double i = b0; i <= e0; i += 0.0025) {
    Point p = c0; p.x += r0; p = p.rotateAroundPoint(i, c0);
    ans = min(ans, secondTSearch(p, c1, r1, b1, e1));
  }
  return ans;
  */
}

int main() {
  freopen("circular.in", "r", stdin);
  freopen("circular.out", "w", stdout);

  double x0, y0, r0, b0, e0;
  scanf("%lf %lf %lf %lf %lf", &x0, &y0, &r0, &b0, &e0);

  double x1, y1, r1, b1, e1;
  scanf("%lf %lf %lf %lf %lf", &x1, &y1, &r1, &b1, &e1);

  b0 = degToRad(b0);
  e0 = degToRad(e0);

  b1 = degToRad(b1);
  e1 = degToRad(e1);

  if(b0 > e0) e0 += 2 * pi;
  if(b1 > e1) e1 += 2 * pi;

  Point c0 = Point(x0, y0);
  Point c1 = Point(x1, y1);

  double ans = firstTSearch(c0, r0, b0, e0, c1, r1, b1, e1);
  printf("%.10lf\n", ans);
  return 0;
}