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

const int N = 100001;

struct point {
  double x, y;
  point(){};
  point(double _x, double _y) {
    x = _x;
    y = _y;
  }
};

struct line {
  double m, b;
  line(){};
  line(double _m, double _b) {
    m = _m;
    b = _b;
  }
  void read(){ scanf("%lf %lf", &m, &b); }
  double value(double x) {
    return m * x - b;
  }
  point intersection(line other) {
    double x = (b - other.b) / (m - other.m);
    double y = other.value(x);
    return point(x, y);
  }
  double valueY(double y) {
    return (y + b) / m;
  }
};

bool cmpAsc(line a, line b) {
  if(fabs(a.m - b.m) > eps) return a.m < b.m;
  return a.b < b.b;
}

bool cmpDesc(line a, line b) {
  if(fabs(a.m - b.m) > eps) return a.m < b.m;
  return a.b > b.b;
}

int n;
line all[N * 2];
line ax[N * 2];


inline void bruteSol() {
  double maxX, maxY, minX, minY;
  maxX = maxY = -HUGE_VAL;
  minX = minY = HUGE_VAL;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(fabs(all[i].m - all[j].m) < eps) continue;
      point p = all[i].intersection(all[j]);
      maxX = max(maxX, p.x);
      maxY = max(maxY, p.y);
      minX = min(minX, p.x);
      minY = min(minY, p.y);
    }
  }
  printf("%.10lf %.10lf %.10lf %.10lf\n", minX, minY, maxX, maxY);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) all[i].read();
  if(n == 1) {
    printf("%.10lf %.10lf %.10lf %.10lf\n", 0, all[0].value(0), 0, all[0].value(0));
    return 0;
  }

  //bruteSol();


  sort(all, all + n, cmpAsc);
  for(int i = 0; i < n; ++i) ax[i] = all[i];
  sort(ax, ax + n, cmpDesc);
  for(int i = 0; i < n; ++i) all[i + n] = ax[i];
  all[n * 2] = all[0];
  n = n * 2 + 1;


  double maxX, maxY, minX, minY;
  maxX = maxY = -HUGE_VAL;
  minX = minY = HUGE_VAL;

  for(int i = 1; i < n; ++i) {
    if(fabs(all[i - 1].m - all[i].m) > eps) {
      point p = all[i].intersection(all[i - 1]);
      maxX = max(maxX, p.x);
      maxY = max(maxY, p.y);
      minX = min(minX, p.x);
      minY = min(minY, p.y);
    }
  }


  printf("%.10lf %.10lf %.10lf %.10lf\n", minX, minY, maxX, maxY);
  return 0;
}