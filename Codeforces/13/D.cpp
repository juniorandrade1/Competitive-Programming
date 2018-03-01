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
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read(){ 
    double _x, _y;
    scanf("%lf %lf", &_x, &_y);
    x = _x;
    y = _y;
  }
  ll operator % (Point other) { return x * other.y - other.x * y; }
  ll operator * (Point other) { return x * other.x + y * other.y; }
  Point operator * (double t) { return Point(x * t, y * t); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  ld norm() { return sqrt(x * x + y * y); }
  ld distToPoint(Point other) {
    return hypot(other.y - y, other.x - x);
  }
};

const int N = 501;

int n, m;
Point bd[N], rd[N];
int pd[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) rd[i].read();
  for(int i = 0; i < m; ++i) bd[i].read();
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(rd[i].x >= rd[j].x) continue;
      for(int k = 0; k < m; ++k) {
        if(rd[i].x <= bd[k].x && bd[k].x < rd[j].x) pd[i][j] += ((rd[i] - bd[k]) % (rd[j] - bd[k])) >= 0;
      }
      pd[j][i] = -pd[i][j];
    }
  }
  int sol = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      for(int k = j + 1; k < n; ++k) {
        sol += ((pd[i][j] + pd[j][k] + pd[k][i]) == 0);
      }
    }
  }
  printf("%d\n", sol);
  return 0;
}