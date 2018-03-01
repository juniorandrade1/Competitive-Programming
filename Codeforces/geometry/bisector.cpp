#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pi acos(-1.0)

struct Point {
  ld x, y;
  Point(){};
  Point(ld _x, ld _y) {
    x = _x;
    y = _y;
  }
  void read(){ 
    double _x, _y;
    scanf("%lf %lf", &_x, &_y);
    x = _x;
    y = _y;
  }
  ld angle(){ return atan2(y, x); }
  ld operator % (Point other) { return x * other.y - other.x * y; }
  ld operator * (Point other) { return x * other.x + y * other.y; }
  Point operator * (ld t) { return Point(x * t, y * t); }
  Point operator / (ld t) { return Point(x / t, y / t); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  ld norm() { return sqrt(x * x + y * y); }
  ld distToPoint(Point other) {
    return hypot(other.y - y, other.x - x);
  }
};

int main() {
  //freopen("bisector.in", "r", stdin);
  //freopen("bisector.out", "w", stdout); 
  Point x, y, z;
  x.read();
  y.read();
  z.read();
  Point zx = z - x;
  Point yx = y - x;
  double ang = (zx.angle() + yx.angle()) * 0.5;
  Point p = Point(x.x + cos(ang), x.y + sin(ang));
  printf("%.10lf %.10lf %.10lf\n", x.y - p.y, p.x - x.x, p % x);
  return 0;
}