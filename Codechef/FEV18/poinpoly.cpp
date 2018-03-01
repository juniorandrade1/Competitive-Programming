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

bool PointIsInsideConvexPolygon(vector< Point > &a, Point p, bool strict) {
  Point vp = p - a[0];
  if((a[1] - a[0]) % vp > -strict) return 0;
  int lo = 1, hi = a.size() - 1;
  while(lo < hi) {
    int md = (lo + hi + 1) >> 1;
    if((a[md] - a[0]) % vp <= -strict) lo = md;
    else hi = md - 1;
  }
  if(hi == a.size() - 1) return false;
  return ((a[lo + 1] - a[lo]) % (p - a[lo])) <= -strict;
}

const int N = 100001;

int n;
map< Point, bool > vis;
vector< Point > sol;

inline void main2() {
  vis.clear();
  sol.clear();
  scanf("%d", &n);
  vector< Point > p(n);
  for(int i = 0; i < n; ++i) p[i].read();
  vector< Point > ch = convexHull(p);
  reverse(ch.begin(), ch.end());
  queue< Point > q; 
  for(int i = 0; i < ch.size(); ++i) {
    q.push(ch[i]);
    vis[ch[i]] = 1;
  }
  int need = n / 10;
  while(!q.empty() && sol.size() < need) {
    Point p = q.front(); q.pop();
    for(int i = -1; i <= 1 && sol.size() < need; ++i) {
      for(int j = -1; j <= 1 && sol.size() < need; ++j) {
        ll xx = i + p.x, yy = j + p.y;
        Point np = Point(xx, yy);
        if(vis[np]) continue;
        if(!PointIsInsideConvexPolygon(ch, np, false)) continue;
        if(PointIsInsideConvexPolygon(ch, np, true)) sol.push_back(np);
        vis[np] = true;
        q.push(np);
      }
    }
  }
  if(sol.size() != need) puts("-1");
  else {
    for(int i = 0; i < sol.size(); ++i) {
      printf("%lld %lld\n", sol[i].x, sol[i].y);
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0; 
}