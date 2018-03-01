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
  Point(){
    x = rand() % 1000000 + 1;
    y = rand() % 1000000 + 1;
  };
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
bitset<N> me[N][N], md[N][N];

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    for(int i = 0; i < n; ++i) rd[i].read();
    for(int i = 0; i < m; ++i) bd[i].read();
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        me[i][j].reset(); me[j][i].reset();
        md[i][j].reset(); md[j][i].reset();
        for(int k = 0; k < m; ++k) {
          bool yes = ((rd[i] - bd[k]) % (rd[j] - bd[k])) >= 0;
          if(!yes) me[i][j].set(k);
          else md[i][j].set(k);
          if(yes) me[j][i].set(k);
          else md[j][i].set(k);
        }
      }
    }

    ll sol = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        for(int k = j + 1; k < n; ++k) {
          bitset<N>ae = (me[i][j] & me[j][k] & me[k][i]);
          bitset<N>ad = (md[i][j] & md[j][k] & md[k][i]);
          ll esq = ae.count();
          ll dir = ad.count();
          sol += (esq * esq + dir * dir);
        }
      }
    }
    printf("%lld\n", sol);
  }
  return 0;
}