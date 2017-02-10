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
#define PI acos(-1)
#define eps 1e-6

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
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
};

struct Line {
  double a, b, c;
  Line(){};
  Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  Line(Point s, Point t) {
    a = t.y - s.y;
    b = s.x - t.x;
    c = -a * s.x - b * s.y;
  }
  bool parallel(Line other) { return fabs(a * other.b - b * other.a) < eps; }
  Point intersect(Line other) {
    if(this->parallel(other)) return Point(-HUGE_VAL, -HUGE_VAL);
    else {
      double determinant = this->b * other.a - this->a * other.b;
      double x = (this->c * other.b - this->b * other.c) / determinant;
      double y = (this->a * other.c - this->c * other.a) / determinant;
      return Point(x, y);
    }
  }
  Line perpendicular(Point point) {
    return Line(-b, a, b * point.x - a * point.y);
  }
};

struct Circle {
  double x, y, r;
  Circle(){};
  Circle(double _x, double _y, double _r) {
    x = _x;
    y = _y;
    r = _r;
  }
  Circle(Point a, Point b, Point c) {
    Line ab = Line(a, b);
    Line bc = Line(b, c);
    double xAB = (a.x + b.x) * 0.5;
    double yAB = (a.y + b.y) * 0.5;
    double xBC = (b.x + c.x) * 0.5;
    double yBC = (b.y + c.y) * 0.5;
    ab = ab.perpendicular(Point(xAB, yAB));
    bc = bc.perpendicular(Point(xBC, yBC));
    if(ab.parallel(bc)) {
      x = -1;
      y = -1;
      r = -1;
    }
    Point center = ab.intersect(bc);
    x = center.x;
    y = center.y;
    r = center.distance(a);
  }
};

const int N = 55;

Point p[N];
int n;
ll R;

vi inside, outside;

inline ll go(vi sweep) {
  ll ans = 0;
  set< ii > s;
  int lst = 0;
  for(int i = 0; i < sweep.size(); ++i) {
    int idx = sweep[i];
    while(lst < i && round(p[idx].x) - round(p[sweep[lst]].x) > R) {
      s.erase(s.find(mp(round(p[sweep[lst]].y), sweep[lst])));
      lst++;
    }
    int x = round(p[idx].x);
    int y = round(p[idx].y);
    s.insert(mp(y, idx));
    set< ii > :: iterator itS = s.lower_bound(mp(y - R, -INF));
    set< ii > :: iterator itE = s.upper_bound(mp(y + R, INF));
    set< ii > :: iterator otherPointer = itS;
    ll qtd = 0;
    for(set<ii> :: iterator it = itS; it != itE; it++) {
      qtd++;
      while(it->F - otherPointer->F > R) otherPointer++, qtd--;
      ans = max(ans, qtd);
    }
  }
  return ans;
}

inline ll solve(Circle c) {
  if(c.r < 0) return 0;
  inside.clear();
  outside.clear();
  for(int i = 0; i < n; ++i) {
    double distance = p[i].distance(Point(c.x, c.y));
    if(distance <= c.r) inside.pb(i);
    else outside.pb(i);
  }
  return go(inside) + go(outside);
}

inline void main2() {
  scanf("%d %lld", &n, &R);
  for(int i = 0; i < n; ++i) p[i].read();
  sort(p, p + n);
  ll ans = 0;
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) for(int k = j + 1; k < n; ++k) ans = solve(Circle(p[i], p[j], p[k]));
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) ans = max(ans, solve(Circle((p[i].x + p[j].x) * 0.5, (p[i].y + p[j].y) * 0.5, p[i].distance(p[j]) * 0.5)));
  for(int i = 0; i < n; ++i) ans = max(ans, solve(Circle(p[i].x, p[i].y, 0)));
  printf(" %lld\n", ans);
}

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}