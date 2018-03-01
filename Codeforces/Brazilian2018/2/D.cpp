#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

typedef long long ll;

struct Point {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) { x = _x; y = _y; }
  void read(){ scanf("%lld %lld", &x, &y); }
  bool operator < (Point other) const {
    if(x != other.x) return x < other.x;
    return y < other.y;
  }
  bool operator == (Point other) { return x == other.x && y == other.y; }
  ll operator % (Point other) { return x * other.y - other.x * y; }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  long double getDistance(Point other) {  return sqrt((1.0 * x - other.x) * (1.0 * x - other.x) + (1.0 * y - other.y) * (1.0 * y - other.y)); }
};

vector< Point > convexHull(vector< Point > &s) {
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  vector< Point > lh, uh;
  int ls = 0, us = 0;
  for(int i = 0; i < s.size(); ++i) {
    while(ls >= 2 && (lh[ls - 1] - lh[ls - 2]) % (s[i] - lh[ls - 1]) <= 0) lh.pop_back(), ls--;
    while(us >= 2 && (uh[us - 1] - uh[us - 2]) % (s[i] - uh[us - 1]) >= 0) uh.pop_back(), us--;
    lh.push_back(s[i]); ls++;
    uh.push_back(s[i]); us++;
  }
  for(int i = (int)uh.size() - 2; i > 0; --i) lh.push_back(uh[i]);
  return lh;
}

bool PointIsInsideConvexPolygon(vector< Point > &a, Point p) {
  Point vp = p - a[0];
  if((a[1] - a[0]) % vp > 0) return 0;
  int lo = 1, hi = a.size() - 1;
  while(lo < hi) {
    int md = (lo + hi + 1) >> 1;
    if((a[md] - a[0]) % vp < 0) lo = md;
    else hi = md - 1;
  }
  if(hi == a.size() - 1) return false;
  return ((a[lo + 1] - a[lo]) % (p - a[lo])) <= 0;
}

const int N = 100001;

int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  vector< Point > p(n);
  for(int i = 0; i < n; ++i) p[i].read();
  vector< Point > ch = convexHull(p);
  reverse(ch.begin(), ch.end());
  int q = 0;
  for(int i = 0; i < m; ++i) {
    Point p; p.read();
    q += PointIsInsideConvexPolygon(ch, p);
  }
  puts(q >= k ? "YES" : "NO");
  
  return 0; 
}