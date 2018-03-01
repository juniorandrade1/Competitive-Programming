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
#define eps 1e-9

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
  double distance(Point p) {
    return fabs(a * p.x + b * p.y + c);
  }
};

struct Segment {
  Point a, b;
  Segment(){};
  Segment(Point _a, Point _b) {
    a = _a;
    b = _b;
  }
  double distance(Point point) {
    double length = a.distance(b);
    double left = point.distance(a);
    if (length < eps) return left;
    double right = point.distance(b);
    if (left * left > right * right + length * length) return right;
    if (right * right > left * left + length * length) return left;
    return Line(a, b).distance(point);
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
  void read() {
    scanf("%lf %lf %lf", &x, &y, &r);
  }
  bool intersect(Circle c) {
    double d = hypot(x - c.x, y - c.y);
    return d <= r + c.r + eps;
  }
  double getIntersectionArea(Circle c) {
    double d = hypot(x - c.x, y - c.y);
    if(d >= r + c.r) return 0.0;
    else if (c.r >= d + r) return pi * r * r;
    else if (r >= d + c.r) return pi * c.r * c.r;
    else {
      double a1 = 2.*acos((d * d + r * r - c.r * c.r) / (2. * d * r));
      double a2 = 2.*acos((d * d + c.r * c.r - r * r) / (2. * d * c.r));
      double num1 = (ld)a1 / 2. * r * r - r * r * sin(a1) * 0.5;
      double num2 = (ld)a2 / 2. * c.r * c.r - c.r * c.r * sin(a2)*0.5;
      return num1 + num2;
    }
  }
};

struct Geometry {
  double canonicalAngle(double angle) {
    if(angle < -pi) angle += 2. * pi;
    if(angle > pi) angle -= 2. * pi;
    return angle;
  }
  double getAngle(Point a, Point o, Point b) { //angle between aob
    return canonicalAngle(atan2(a.y - o.y, a.x - o.x) - atan2(b.y - o.y, b.x - o.x));
  }
} GeometryUtils;

const int N = 1001;

int b, n, m;
Point poly[N];
Point informers[N];
Circle radar[N];

vi g[N];
int vis[N];

bool insidePolygon(Point point) {
  double ang = 0;
  for(int i = 0; i < b; ++i) {
    int lst = (i - 1 + b) % b;
    ang += GeometryUtils.canonicalAngle(atan2(poly[i].y - point.y, poly[i].x - point.x) 
      - atan2(poly[lst].y - point.y, poly[lst].x - point.x));
  }
  return fabs(ang) > pi;
}

double getInfiltration(Point point) {
  double w = HUGE_VAL;
  for(int i = 0; i < b; ++i) {
    int nxt = (i + 1) % b;
    Segment seg = Segment(poly[i], poly[nxt]);
    w = min(w, seg.distance(point));
  }
  return w;
}

bool dfs(int x, double ang, Point point) {
  if(vis[x]) return fabs(ang) > pi;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    double gAng = GeometryUtils.getAngle(Point(radar[x].x, radar[x].y), Point(radar[y].x, radar[y].y), point);
    if(dfs(y, ang, point)) return true;
  }
  return false;
}

inline bool canReach(Point point) {
  for(int i = 0; i < m; ++i) vis[i] = 0;
  for(int i = 0; i < m; ++i) {
    double d = point.distance(Point(radar[i].x, radar[i].y));
    if(d + eps <= radar[i].r) return false;
  }
  bool ok = 1;
  for(int i = 0; i < m && ok; ++i) {
    memset(vis, 0, sizeof vis);
    if(vis[i] == 0) {
      ok &= (1 - dfs(i, 0, point));
    } 
  }
  return ok;
}

int main() {
  while(1) {
    scanf("%d", &b);
    for(int i = 0; i < b; ++i) poly[i].read();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) informers[i].read();
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) radar[i].read();
    if(!b && !n && !m) break;

    bool zica = false;

    for(int i = 0; i < m; ++i) {
      double d = Point(2000, 2000).distance(Point(radar[i].x, radar[i].y));
      if(d + eps <= radar[i].r) zica = true;
      g[i].clear();
    }

    if(zica) {
      puts("Mission impossible");
      continue;
    }

    for(int i = 0; i < m; ++i) for(int j = i + 1; j < m; ++j) if(radar[i].intersect(radar[j])) {
      g[i].pb(j);
      g[j].pb(i);
    }
    double bst = -1;
    int idx = -1;
    for(int i = 0; i < n; ++i) {
      if(insidePolygon(informers[i])) {
        double w = getInfiltration(informers[i]);
        if(canReach(informers[i])) {
          bst = max(bst, w);
          idx = i + 1;
        }
      }
    }
    if(idx == -1) printf("Mission impossible\n");
    else printf("Contact informer %d\n", idx);
  }
  return 0;
}