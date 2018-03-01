#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

struct Point {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lld %lld", &x, &y); }
  double operator % (Point other) { return x * other.y - other.x * y; }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
};

typedef vector < Point > Polygon;

bool PointIsInsideConvexPolygon(Polygon &a, Point p) { //CW order
  Point vp = p - a[0];
  if((a[1] - a[0]) % vp > 0) return 0;
  int lo = 1, hi = a.size() - 1;
  while(lo < hi) {
    int md = (lo + hi + 1) >> 1;
    if((a[md] - a[0]) % vp < 0) lo = md;
    else hi = md - 1;
  }
  if(hi == a.size() - 1) return false;
  return ((a[lo + 1] - a[lo]) % (p - a[lo])) < 0;
}

bool PolygonIsInsideOther(Polygon &a, Polygon &b) {
  bool ok = true;
  for(int i = 0; i < b.size() && ok; ++i) ok &= PointIsInsideConvexPolygon(a, b[i]);
  return ok;
}

int n, m;
Polygon pa, pb;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    Point p; p.read();
    pa.pb(p);
  }
  for(int i = 0; i < m; ++i) {
    Point p; p.read();
    pb.pb(p);
  }
  bool ok = PolygonIsInsideOther(pa, pb) | PolygonIsInsideOther(pb, pa);
  puts(ok ? "YES" : "NO");
  return 0;
}