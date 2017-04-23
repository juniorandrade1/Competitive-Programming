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

const int N = 110;
const int M = 2200;

#define pi acos(-1.0)
#define eps 1e-6

struct Point {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lld %lld", &x, &y); }
  Point operator -= (Point other) const {
    return Point(x - other.x, y - other.y);
  }
  void print() {
    printf("(%lld %lld)\n", x, y);
  }
  ll distanceSquared(Point other) {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
  }
};

class GeometricUtils {
  public:
    GeometricUtils(){};
    static ll cross(Point a, Point b, Point c) {
      ll dx1 = (a.x - b.x), dy1 = (a.y - b.y);
      ll dx2 = (c.x - b.x), dy2 = (c.y - b.y);
      return (dx1 * dy2 - dx2 * dy1);
    }
    static bool above(Point a, Point b, Point c) {
      return cross(a, b, c) < 0;
    }
    static bool under(Point a, Point b, Point c) {
      return cross(a, b, c) > 0;
    }
    static bool sameLine(Point a, Point b, Point c) {
      return cross(a, b, c) == 0;
    }
};

int n, area;
Point allP[N];

bool cmp(Point a, Point b) {
  if(GeometricUtils::sameLine(a, allP[0], b)) return a.distanceSquared(allP[0]) < b.distanceSquared(allP[0]);
  return GeometricUtils::under(a, allP[0], b);
}

int pd[N][N][M];
short memo[N][N][M];

int func(int fst, int snd, int qtd) {
  if(memo[fst][snd][qtd]) return pd[fst][snd][qtd];
  memo[fst][snd][qtd] = 1;
  int ret = qtd;
  for(int i = snd + 1; i <= n; ++i) {
    if(GeometricUtils::above(allP[fst], allP[snd], allP[i])) {
      int foo = abs(GeometricUtils::cross(allP[snd], allP[i], allP[0]));
      if(qtd + foo <= area * 2) ret = max(ret, func(snd, i, qtd + foo));
    }
  }
  return pd[fst][snd][qtd] = ret;
}

int main() {
  scanf("%d %d", &n, &area);
  allP[0].read();
  for(int i = 1; i <= n; ++i) allP[i].read();
  sort(allP + 1, allP + n + 1, cmp);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans = max(ans, func(0, i, 0));
  }
  if(ans % 2 == 0) printf("%d\n", ans / 2);
  else printf("%d.5\n", ans / 2);
  return 0;
}