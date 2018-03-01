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

struct Circle {
  Point c;
  double r;
  Circle(){};
  Circle(Point _c, double _r) {
    c = _c;
    r = _r;
  }
  void read() {
    c.read();
    scanf("%lf", &r);
  }
};



const int N = 100001;

Point s, t;
Circle c;

int main() {
  s.read();
  t.read();
  c.read();

  return 0; 
}