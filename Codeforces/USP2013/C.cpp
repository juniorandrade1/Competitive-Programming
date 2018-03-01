#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define eps 1e-9

inline int cmp(ld x, ld y = 0, ld tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  ld x, y, z;
  point(ld x = 0, ld y = 0, ld z = 0): x(x), y(y), z(z) {}
  point operator +(point q) { return point(x + q.x, y + q.y, z + q.z); }
  point operator -(point q) { return point(x - q.x, y - q.y, z - q.z); }
  point operator *(ld t) { return point(x * t, y * t, z * t); }
  point operator /(ld t) { return point(x / t, y / t, z / t); }
  point operator %(point q) { return point(y*q.z - z*q.y, z*q.x - x*q.z, x*q.y - y*q.x); }
  ld operator *(point q) { return x * q.x + y * q.y + z * q.z; }
  ld mod() { return sqrt(x * x + y * y + z * z); }
  ld mod2() { return x * x + y * y + z * z; }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    if (int t = ::cmp(y, q.y)) return t;
    return ::cmp(z, q.z);
  }
  bool operator ==(point q) const { return cmp(q) == 0; }
  bool operator !=(point q) const { return cmp(q) != 0; }
  bool operator < (point q) const { return cmp(q) < 0; }
};

inline bool visible(point a, point b, point c, point t, point o) {
  point cs = (b - a) % (c - a);
  ld ax = (cs * a);
  point pt = (cs * t - ax);
  point po = (cs * o - ax);
  return cmp(pt * po, 0) < 0;
}

int main() {
  int t; scanf("%d", &t);
  while(t--)  {
    point p[4]; 
    for(int i = 0; i < 4; ++i) {
      double x, y, z; scanf("%lf %lf %lf", &x, &y, &z);
      p[i] = point(x, y, z);
    }
    double x, y, z; scanf("%lf %lf %lf", &x, &y, &z);
    point o = point(x, y, z);
    printf("%c", visible(p[1], p[2], p[3], p[0], o) ? 'Y' : 'N');
    printf("%c", visible(p[0], p[2], p[3], p[1], o) ? 'Y' : 'N');
    printf("%c", visible(p[0], p[1], p[3], p[2], o) ? 'Y' : 'N');
    printf("%c", visible(p[0], p[1], p[2], p[3], o) ? 'Y' : 'N');
    printf("\n");
  }
  return 0;
}