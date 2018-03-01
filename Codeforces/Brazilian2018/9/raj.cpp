#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 606;
const int M = 10001;

struct Point {
  ll x, y, w;
  Point(){};
  Point(ll _x, ll _y, ll _w) {
    x = _x;
    y = _y;
    w = _w;
  }
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
    w = -1;
  }
  bool operator < (Point o) const {
    if(x != o.x) return x < o.x;
    return y < o.y;
  }
  Point operator - (Point o) const {
    return Point(x - o.x, y - o.y);
  }
  ll operator % (Point o) const { return x * o.y - y * o.x; }
  void read2() {
    scanf("%lld %lld", &x, &y);
  }
  void read3() {
    scanf("%lld %lld %lld", &x, &y, &w);
  }
};

Point p[N];
Point f[M];
int n, m;
ll foo;

Point pivot;

bool cmp(Point a, Point b) {
  return (a - pivot) % (b - pivot) <= 0;
}

inline bool insideTriangle(Point a, Point b, Point c, Point s) {
  return ((b - a) % (s - a) <= 0) && ((c - b) % (s - b) <= 0) && ((a - c) % (s - c) <= 0);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read2();
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) f[i].read3();
  ll ans = -LINF;
  for(int i = 0; i < n; ++i) {
    int x = i;
    pivot = p[x];
    sort(f, f + m, cmp);
    for(int j = i + 1; j < i + n; ++j) {
      int y = (j % n);
      foo = 0;
      int ss = 0;
      while((p[y] - p[x]) % (f[ss] - p[x]) > 0) ss++;
      int se = ss;
      for(int k = j + 1; k < i + n; ++k) {
        int lz = (k - 1) % n;
        int z = (k % n);
        while(se < m && insideTriangle(p[x], p[y], p[z], f[se])) foo += f[se++].w;
        while(k != j + 1 && ss < se && insideTriangle(p[x], p[y], p[lz], f[ss])) foo -= f[ss++].w;
        ans = max(ans, foo);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
} 