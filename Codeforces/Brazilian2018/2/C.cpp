#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

typedef long long ll;

struct Point {
  ll x, y;
  int id;
  Point(){};
  Point(ll _x, ll _y) { x = _x; y = _y; }
  void read(int _id){ scanf("%lld %lld", &x, &y); id = _id; }
  bool operator < (Point other) const {
    if(x != other.x) return x < other.x;
    return y < other.y;
  }
  bool operator == (Point other) { return x == other.x && y == other.y; }
  ll operator % (Point other) { return x * other.y - other.x * y; }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  long double getDistance(Point other) {
    return sqrt((1.0 * x - other.x) * (1.0 * x - other.x) + (1.0 * y - other.y) * (1.0 * y - other.y));
  }
};

const int N = 200001;

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

long double getPerimeter(vector< Point > &poly) {
  int n = poly.size();
  long double ans = 0;
  for(int i = 0; i < n; ++i) ans += poly[i].getDistance(poly[(i + 1) % n]);
  return ans;
}

ll getAreaMultipliedBy2(vector< Point > &poly) {
  int n = poly.size();
  ll area = 0;
  for(int i = 1; i + 1 < n; ++i) {
    area += (poly[i] - poly[0]) % (poly[i + 1] - poly[0]);
  }
  if(area < 0) area *= -1LL;
  return area;
}

int main() {
  int n; scanf("%d", &n);
  vector< Point > p(n);
  for(int i = 0; i < n; ++i) p[i].read(i + 1);
  vector< Point > ch = convexHull(p);
  printf("%d\n", (int)ch.size());
  for(int i = 0; i < (int)ch.size(); ++i) {
    if(i) printf(" ");
    printf("%d", ch[i].id);
  }
  printf("\n");
  long double per = getPerimeter(ch);
  printf("%.20lf\n", (double)per);
  ll are = getAreaMultipliedBy2(ch);
  printf("%lld", are >> 1LL);
  if(are & 1) printf(".5\n");
  else printf(".0\n");
  return 0; 
}