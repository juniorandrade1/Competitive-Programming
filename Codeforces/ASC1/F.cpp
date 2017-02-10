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
#define eps 1e-6

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lf %lf", &x, &y); }
  double distance(Point other) { return hypot(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(double t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
};

struct Line {
  double a, b, c;
  Line(){};
  Line(Point s, Point t) {
    a = t.y - s.y;
    b = s.x - t.x;
    c = -a * s.x - b * s.y;
  }
  bool parallel(Line other) { return fabs(a * other.b - b * other.a) < eps; }
  Point intersect(Line other) {
    if(this->parallel(other)) return Point(LINF, LINF);
    else {
      double determinant = this->b * other.a - this->a * other.b;
      double x = (this->c * other.b - this->b * other.c) / determinant;
      double y = (this->a * other.c - this->c * other.a) / determinant;
      return Point(x, y);
    }
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
  double distanceBetweenPoints() { return hypot(s.x - t.x, s.y - t.y); }
  bool intersectOtherSegment(Segment other) {
    Point pInt = l.intersect(other.l);
    //printf("%.2lf %.2lf\n", pInt.x, pInt.y);
    double d00 = distanceBetweenPoints(), d01 = s.distance(pInt), d02  = t.distance(pInt);
    double d10 = other.distanceBetweenPoints(), d11 = other.s.distance(pInt), d12 = other.t.distance(pInt);
    //printf("%.2lf %.2lf\n", fabs(d00 - d01 - d02), fabs(d10 - d11 - d12));
    return fabs(d00 - d01 - d02) < eps && fabs(d10 - d11 - d12) < eps;
  }
};

const int N = 303;


double X[N], Y[N], R[N], A[N];
double x, y, r;
int n;
vector< pair<double, int> > sweep;

int main() {
  //freopen("out.in","r",stdin);
  //freopen("out.out","w",stdout);

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lf %lf %lf", X + i, Y + i, R + i);
  scanf("%lf %lf %lf", &x, &y, &r);
  for(int i = 0; i < n; ++i) {
    double d = hypot(x - X[i], y - Y[i]);
    if(d <= R[i] + r) {
      printf("NO\n");
      return 0;
    }
    X[i] -= x;
    Y[i] -= y;
    A[i] = atan2(Y[i], X[i]);
  }

  Segment leftInfinity = Segment(Point(0, 0), Point(-10000000000000., 0));

  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
    double d = hypot(X[i] - X[j], Y[i] - Y[j]);
    if(d - R[i] - R[j] < 2. * r)  {
      Segment seg = Segment(Point(X[i], Y[i]), Point(X[j], Y[j]));
      //debug("%d %d\n", i + 1, j + 1);
      if(seg.intersectOtherSegment(leftInfinity)) { 
        //debug("type 2 = %d %d\n", i + 1, j + 1);
        sweep.pb(mp(-PI, -1));
        sweep.pb(mp(min(A[i], A[j]), 1));
        sweep.pb(mp(max(A[i], A[j]), -1));
        sweep.pb(mp(PI, 1));
      }
      else {
        //debug("type 1 = %d %d\n", i + 1, j + 1);
        sweep.pb(mp(min(A[i], A[j]), -1));
        sweep.pb(mp(max(A[i], A[j]), 1));
      }
    }
  }


  sort(sweep.begin(), sweep.end());


  int i = 0;
  int qtd = 0;
  while(i < sweep.size() && fabs(sweep[i].F + PI) < eps) {
    qtd++;
    i++;
  }
  if(qtd == 0) {
    printf("YES\n");
    return 0;
  }
  for(; i < sweep.size(); ++i) {
    if(fabs(sweep[i].F - PI) < eps) {
      break;
    }
    qtd -= sweep[i].S;
    if(qtd == 0) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}