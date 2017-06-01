#include <bits/stdc++.h>
using namespace std;

//typedef long long int;
//typedef long double ld;
typedef pair< int, int > ii;
typedef vector< int > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
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
#define eps 1e-6

struct Point {
  int x, y;
  Point(){};
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%d %d", &x, &y); }
  int distance(Point other) { return hypot(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator * (int other) { return Point(x * other, y * other); }
  Point operator / (int t) { return Point(x / t, y / t); }
  int operator * (Point q) {return x * q.x + y * q.y;} //a*b = |a||b|cos(ang) //Positivo se o vetor B está do mesmo lado do vetor perpendicular a A
  int operator % (Point q) {return x * q.y - y * q.x;} //a%b = |a||b|sin(ang) //Angle of vectors
  int polar() { return ((y > -eps) ? atan2(y,x) : 2*pi + atan2(y,x)); }
  Point rotate(int t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(int t, Point p) {
    Point foo = Point(x - p.x, y - p.y);
    foo = foo.rotate(t);
    return foo + p;
  }
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
};


int getPolygonArea(vector<Point> poly) {
  if(poly.size() == 1) return 0;
  int sum = 0;
  for (int i = 1; i < poly.size(); i++) sum += (poly[i].x - poly[i - 1].x) * (poly[i].y + poly[i - 1].y);
  sum += (poly[0].x - poly[poly.size() - 1].x) * (poly[0].y + poly[poly.size() - 1].y);
  if(sum < 0) sum = -sum;
  return sum;
}

vector< Point > ConvexHuint(vector< Point > &polygon) {
  sort(polygon.begin(), polygon.end());
  vector< Point > down, up;
  up.pb(polygon[0]);
  up.pb(polygon[1]);
  down.pb(polygon[0]);
  down.pb(polygon[1]);
  for(int i = 2; i < polygon.size(); ++i) {
    while(up.size() >= 2 && (up[up.size() - 1] - up[up.size() - 2]) % (polygon[i] - up[up.size() - 1]) > 0) up.pop_back();
    while(down.size() >= 2 && (down[down.size() - 1] - down[down.size() - 2]) % (polygon[i] - down[down.size() - 1]) < 0) down.pop_back();
    up.pb(polygon[i]);
    down.pb(polygon[i]);
  }
  for(int i = (int)down.size() - 2; i > 0; --i) up.pb(down[i]);
  return up;
}

const int N = 201;

int test = 1;
Point p[N];
int n, k;

Point PIVOT;

bool cmpPivot(Point a, Point b) {
  return atan2(a.y - PIVOT.y, a.x - PIVOT.x) <  atan2(b.y - PIVOT.y, b.x - PIVOT.x);
}

short memo[N][51][101];
int pd[N][51][101];
vector< Point > poly;

short memoArea[N][N];
int pdArea[N][N];

int getArea(int x, int y) {
  if(memoArea[x][y] == test) return pdArea[x][y];
  memoArea[x][y] = test;
  vector< Point > foo;
  for(int i = x; i <= y; ++i) foo.pb(poly[i]);
  foo.pb(PIVOT);
  return pdArea[x][y] = getPolygonArea(ConvexHuint(foo));
}

int func(int x, int qtd, int st) {
  if(qtd == 0) return (x == st + n - 1) ? 0 : INF;
  if(x == st + n - 1) return INF;
  if(memo[x][qtd][st] == test) return pd[x][qtd][st];
  memo[x][qtd][st] = test;
  pd[x][qtd][st] = INF;
  for(int i = x + 1; i < st + n - 1; ++i) pd[x][qtd][st] = min(pd[x][qtd][st], getArea(x, i) + func(i + 1, qtd - 1, st));
  return pd[x][qtd][st];
}

inline int solve(int pivot) {
  poly.clear();
  for(int i = 0; i < n; ++i) {
    if(i == pivot) PIVOT = p[i];
    else poly.pb(p[i]);
  }
  sort(poly.begin(), poly.end(), cmpPivot);
  for(int i = 0; i + 1 < n; ++i) poly.pb(poly[i]);
  int ans = INF;
  for(int i = 0; i + 1 < n; ++i) ans = min(ans, func(i, k, i));
  return ans;
}

int main() {
  while(scanf("%d %d", &k, &n) != EOF && n > 0 && k > 0) {
    for(int i = 0; i < n; ++i) p[i].read();
    int ans = solve(0);
    printf("%.2lf\n", ans * 0.5);
    test++;
  } 
  return 0;
}
