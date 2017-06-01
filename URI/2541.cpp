#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
  ll x, y;
  Point() {}
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lld %lld", &x, &y); }
  Point operator - (Point other) const { return Point(x - other.x, y - other.y); }
  ll operator % (Point other) const { return x * other.y - y * other.x; }
  bool operator < (Point other) const {
    if(x != other.x) return x < other.x;
    else y < other.y;
  }
};

vector< Point > p;
int n;

vector< Point > convexHull() {
  vector< Point > up;
  for(int i = 0; i < n; ++i) {
    while(up.size() > 2) {
      int sz = up.size();
      if((up[sz - 2] - p[i]) % (up[sz - 1] - p[i]) <= 0) up.pop_back(); 
      else break;
    }
    up.push_back(p[i]);
  }
  vector< Point > down;
  for(int i = 0; i < n; ++i) {
    while(down.size() > 2) {
      int sz = down.size();
      if((down[sz - 2] - down[i]) % (down[sz - 1] - p[i]) >= 0) down.pop_back(); 
      else break;
    }
    down.push_back(p[i]);
  }
  for(int i = (int)down.size() - 2; i > 0; --i) up.push_back(down[i]);
  return up;
}

ll getAreaPolygon(vector< Point > poly) {
  ll area = 0;
  for(int i = 2; i < n; ++i) area += (p[1] - p[0]) % (p[i] - p[0]);
  if(area < 0) return -area;
  return area;
}

int main() {
  while(scanf("%d", &n) != EOF && n > 0) {
    p.clear();
    for(int i = 0; i < n; ++i) {
      Point s; s.read();
      p.push_back(s);
    }
    sort(p.begin(), p.end());
    vector< Point > poly = convexHull();
    double area = getAreaPolygon(poly);
    printf("%.2lf\n", area * 0.5);
  }
  return 0;
}