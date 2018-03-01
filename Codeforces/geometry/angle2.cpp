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
  ld operator % (Point other) { return x * other.y - other.x * y; }
  ld operator * (Point other) { return x * other.x + y * other.y; }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  ld norm() { return sqrt(x * x + y * y); }
  ld distToPoint(Point other) {
    return hypot(other.y - y, other.x - x);
  }
};

int main() {
  freopen("angle2.in", "r", stdin);
  freopen("angle2.out", "w", stdout); 
  Point a, b;
  a.read();
  b.read();
  ld ang = acos((a * b) / (a.norm() * b.norm()));
  printf("%.10lf\n", (double)ang);
  return 0;
}