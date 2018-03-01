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

const int N = 1001;

struct Point  {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read() {
    scanf("%lld %lld", &x, &y);
  }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  ll operator % (Point other) { return x * other.y - other.x * y; }
  ll squaredDistance() { return (x * x) + (y * y); }
};


int main() {
  Point a, b, c;
  a.read();
  b.read();
  c.read();
  if((b - a) % (c - a) == 0) puts("No");
  else if((a - b).squaredDistance() != (b - c).squaredDistance()) puts("No");
  else puts("Yes");
  return 0;
}