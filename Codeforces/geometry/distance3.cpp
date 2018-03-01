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

#define eps 1e-9

#define pi acos(-1.0)

const int N = 100010;

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

struct Line {
  Point a;
  Point ab;
  Line(){
    a = Point(0, 0);
    ab = Point(1, 0);
  };
  Line(Point _a, Point _b) {
    a = Point(_a);
    ab = Point(_b.x - _a.x, _b.y - _a.y);
  }
  Line(double _a, double _b, double _c) {
    if(fabs(_a) < eps) _a = eps;
    if(fabs(_b) < eps) _b = eps;
    double x0 = rand() % 1000000000 + 1;
    double y1 = rand() % 1000000000 + 1;
    Point s, t;
    s = Point(x0, (-_c - _a * x0) / _b);
    t = Point((-_c - _b * y1) / _a, y1);
    a = Point(s);
    ab = t - s;
  }
  bool insideLine(Point p) {
    return fabs(p % ab) < eps;
  }
  double distToPoint(Point p) {
    if(insideLine(p)) return 0.0;
    return fabs((p - a) % ab) / ab.norm();
  }
};

struct Segment {
  Point s, t;
  Line l;
  Segment(){};
  Segment(Point _s, Point _t) {
    s = _s;
    t = _t;
    l = Line(s, t);
  }
  double distToPoint(Point p) {
    //if((p - s) * (s - t) < 0) return p.distToPoint(s);
    //if((p - t) * (t - s) > 0) return p.distToPoint(t);
    //if((p - s) * (s - t) > 0) 
    //if((p - t) * (s - t) < 0) return p.distToPoint(t);
    return l.distToPoint(p);
  }
};


int main() {
  srand(time(NULL));
  //freopen("distance3.in", "r", stdin);
  //freopen("distance3.out", "w", stdout); 
  Point p; p.read();
  Point a; a.read();
  Point b; b.read();
  Segment l = Segment(a, b);
  printf("%.10lf\n", l.distToPoint(p));

  return 0;
}