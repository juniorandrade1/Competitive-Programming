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


int cmpDouble(double x, double y) {
  if(fabs(x - y) < eps) return 0;
  if(x < y) return -1;
  return 1;
}

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
  Point operator * (double t) { return Point(x * t, y * t); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  ld norm() { return sqrt(x * x + y * y); }
  ld distToPoint(Point other) {
    return hypot(other.y - y, other.x - x);
  }
  bool operator < (Point o) const {
    if(fabs(x - o.x) > eps) return x < o.x;
    return y < o.y;
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
  double distToPoint(Point p) {
    return fabs((p - a) % ab) / ab.norm();
  }
  bool areParallel(Line l) { return cmpDouble(ab % l.ab, 0) == 0; }
  Point intersectionPoint(Line l) {
    // A + iAB
    double i = ((l.ab - a) % l.ab) / (ab % l.ab);
    return a + ab * i;
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
  ld distToPoint(Point p) {
    int o1 = cmpDouble((t - s) * (t - p), 0);
    int o2 = cmpDouble((s - t) * (s - p), 0);
    if(o1 * o2 >= 0) return l.distToPoint(p);
    return min(s.distToPoint(p), t.distToPoint(p));
  }
  ld distToSegment(Segment other) {
    int ds = cmpDouble((t - s) % (other.s - s), 0);
    int dt = cmpDouble((t - s) % (other.t - s), 0);
    int os1 = cmpDouble((t - s) * (t - other.s), 0);
    int os2 = cmpDouble((s - t) * (s - other.s), 0);
    int ot1 = cmpDouble((t - s) * (t - other.t), 0);
    int ot2 = cmpDouble((s - t) * (s - other.t), 0);
    if(os1 * os2 >= 0 && ot1 * ot2 >= 0 && ds * dt <= 0) return 0.0; //Segment intersect
    return min(min(other.distToPoint(s), other.distToPoint(t)), min(distToPoint(other.s), distToPoint(other.t)));
  }
};

vector< Point > getConvexHull(int n, Point p[]) {
  sort(p, p + n);
  vector< Point > up, down;
  for(int i = 0; i < n; ++i) {
    if(up.size() >= 2 && (up[up.size() - 1] - up[up.size() - 2]) % (p[i] - up[up.size() - 2]) <= 0) up.pop_back();
    if(down.size() >= 2 && (down[down.size() - 1] - down[down.size() - 2]) % (p[i] - down[down.size() - 2]) >= 0) down.pop_back();
    up.push_back(p[i]);
    down.push_back(p[i]);
  }
  for(int i = (int)down.size() - 2; i > 0; --i) up.push_back(down[i]);
  return up;
}

const int N = 5100;

int n;
Point p[N];

inline long double getMaxDistance(int l, int r) {
  int i = l;
  int j = (r + 1) % n;
  long double bst = 0;
  while(1) {
    i++;
    if(i >= n) i -= n;
    if(i == r) break;
    while((j + 1) % n != l && p[i].distToPoint(p[j]) < p[i].distToPoint(p[(j + 1) % n])) j++;
    bst = max(bst, p[i].distToPoint(p[j]));
  }
  return bst;
}

int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  vector< Point > ch = getConvexHull(n, p);
  n = ch.size();
  for(int i = 0; i < n; ++i) p[i] = ch[i];
  long double bstArea = 0;

  int j = 1;
  for(int i = 0; i < n; ++i) {
    if(j >= n) j -= n;
    if(p[i].distToPoint(p[j]) < p[i].distToPoint(p[(j + 1) % n])) j++, j %= n;
    bstArea = max(bstArea, (long double)p[i].distToPoint(p[j]) * getMaxDistance(i, j));
  }

  ll areaInteger = round(bstArea);
  printf("%lld", areaInteger >> 1);
  if(areaInteger & 1) printf(".5\n");
  else printf(".0\n");

  return 0;
}