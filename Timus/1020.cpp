#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define PI acos(-1.0)
#define EPS 1e-7

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read() { scanf("%lf %lf", &x, &y); }
  Point operator - (Point o) const { return Point(x - o.x, y - o.y); }
  double operator % (Point o) const { return x * o.y - y * o.x; }
  bool operator < (Point o) const {
    if(fabs(x - o.x) < EPS) return x < o.x;
    else return y < o.y;
  }
  double distance(Point p) {
    return hypot(y - p.y, x - p.x);
  }
};

const int N = 101;

int n;
double d;
Point p[N];

inline vector< Point > ch() {
  vector< Point > up;
  for(int i = 0; i < n; ++i) {
    while(up.size() >= 2) {
      int sz = up.size();
      if((up[sz - 1] - up[sz - 2]) % (p[i] - up[sz - 2]) < EPS) up.pop_back();
      else break;
    }
    up.pb(p[i]);
  }
  vector< Point > down;
  for(int i = 0; i < n; ++i) {
    while(down.size() >= 2) {
      int sz = down.size();
      if((down[sz - 1] - down[sz - 2]) % (p[i] - down[sz - 2]) > -EPS) down.pop_back();
      else break;
    }
    down.pb(p[i]);
  }
  for(int i = (int)down.size() - 2; i > 0; --i) up.pb(down[i]);
  return up;
}

inline double getPolygonArea(vector< Point > &hull) {
  double area = 0;
  for(int i = 0; i < hull.size(); ++i) area += hull[i].distance(hull[(i + 1) % hull.size()]);
  return fabs(area);
}

int main() {
  scanf("%d %lf", &n, &d);
  for(int i = 0; i < n; ++i) p[i].read();
  sort(p, p + n);
  vector< Point > hull = ch();
  double area = getPolygonArea(hull);
  printf("%.2lf\n", area + 2 * PI * d);
  return 0;
}