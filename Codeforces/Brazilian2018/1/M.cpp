#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point  {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read() {
    scanf("%lld %lld", &x, &y);
  }
  ll distSQ(Point p) {
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  }
};

struct Segment{
  Point s, t;
  void read() {
    s.read();
    t.read();
  }
  ll distSQ() {
    return s.distSQ(t);
  }
};

Segment a, b;

int main() {
  a.read();
  b.read();

  ll da = a.distSQ();
  ll db = b.distSQ();

  ll g = __gcd(da, db);
  if(g == 1) puts("NO");
  else{
    puts("YES");  
    double pa = sqrt(da);
    double pb = sqrt(db);
    if(pa < pb) swap(pa, pb);

    printf("%.6lf\n", pb);
  }
  return 0;
}