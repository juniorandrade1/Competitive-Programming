#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point {
  ll x, y;
  Point(){}
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read() {
    scanf("%lld %lld", &x, &y);
  }
  Point operator - (Point other) const {
    return Point(x - other.x, y - other.y);
  }
  double operator % (Point other) const {
    return x * other.y - other.x * y;
  }
};
const int N = 50010;
int n;
Point p[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  ll ans = 0;
  for(int i = 1; i + 1 < n; ++i) ans += (p[i] - p[0]) % (p[i + 1] - p[0]);
  printf("%lld", ans >> 1);
  if(ans & 1) printf(".5\n");
  else printf(".0\n");
  return 0;
}