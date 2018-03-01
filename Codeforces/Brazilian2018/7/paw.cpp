#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
  ll x, y;
  long double ang;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
    ang = atan2(y, x);
  }
  void read() {
    scanf("%lld %lld", &x, &y);
    ang = atan2(y, x);
  }
  ll operator % (Point p) const {
    return x * p.y - y * p.x;
  }
  Point operator + (Point p) const {
    return Point(x + p.x, y + p.y);
  }
  long double norm() { return hypot(x, y); }
  ll squareDistance() { return x * x + y * y; }
};

struct Line {
  Point a, ab;
  Line(){};
  Line(Point _a, Point _ab) {
    a = _a;
    ab = _ab;
  }
  bool insideLine(Point p) {
    return fabs(p % ab) == 0;
  }
  long double distToPoint(Point p) {
    if(insideLine(p)) return 0.0;
    return fabs((p - a) % ab) / ab.norm();
  }
};

bool cmp(Point a, Point b) {
  return a.ang < b.ang;
}

const int N = 200001;

Point p[N];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  sort(p, p + n, cmp);
  for(int i = 1; i < n; ++i) p[i] = p[i] + p[i - 1];
  ll ans = 0;
  int j = 2;
  for(int i = 0; i < n; ++i) {
    Line l = Line(p[i], p[(i + 1) % n] - p[i]);
    while(l.distToPoint(p[j % n]) <= l.distToPoint(p[(j + 1) % n])) j++;
    Point da = p[j] - p[i];
    Point db = p[j] - p[(i + 1) % n];
    ans = max(ans, da.squareDistance());
    ans = max(ans, db.squareDistance());
  }
  printf("%lld\n", ans);
  return 0;
}