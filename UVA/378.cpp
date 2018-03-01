#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct Point {
  ld x, y;
  Point(){};
  Point(ld _x, ld _y) {
    x = _x;
    y = _y;
  }
  void read() { 
    double ax, ay;
    scanf("%lf %lf", &ax, &ay);
    x = ax;
    y = ay;
  }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); };
  Point operator + (Point other) { return Point(x + other.x, y + other.y); };
  ld operator % (Point other) { return x * other.y - y * other.x; }
  ld operator * (Point other) { return x * other.x + y * other.y; }
  Point operator * (double t) { return Point(x * t, y * t); }
};

struct Line {
  Point a, ab;
  Line(){};
  Line(Point s, Point t) {
    a = s;
    ab = (t - s);
  }
  Point intersectionPoint(Line l) {
    // A + iAB
    long double i = ((l.a - a) % l.ab) / (ab % l.ab);
    Point p0 = a + ab * i;
    return p0;
  }
};

inline void solve() {
  Point s1, t1, s2, t2;
  s1.read(); t1.read(); s2.read(); t2.read();
  Line l1 = Line(s1, t1);
  Line l2 = Line(s2, t2);
  if(fabs(l1.ab % l2.ab) < 1e-8) { //colinear
    if(fabs((l1.a - l2.a) % l1.ab) < 1e-8) puts("LINE");
    else puts("NONE");
  }
  else { //has intersection point
    Point p = l1.intersectionPoint(l2);
    printf("POINT %.2lf %.2lf\n", (double)p.x, (double)p.y);
  }
}

int main() {
  int t; scanf("%d", &t);
  puts("INTERSECTING LINES OUTPUT");
  while(t--) solve();
  puts("END OF OUTPUT");
  return 0; 
}