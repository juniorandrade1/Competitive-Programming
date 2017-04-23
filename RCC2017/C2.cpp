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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define eps 1e-8

struct est {
  double a, b, diff, p;
  est(){};
  est(double _a, double _b, double _p) {
    a = _a;
    b = _b;
    diff = (a - b);
    p = _p;
  }
  void read() {
    scanf("%lf %lf %lf", &a, &b, &p);
    diff = (a - b);
  }
  bool operator < (est foo) const {
    return diff * foo.p < foo.diff * p;
  }
};

const int N = 100002;

est lev[N];
int n;

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) lev[i].read();
  sort(lev, lev + n);
  ld ans = 0;
  ld sumDiff = 0;
  for(int i = 0; i < n; ++i) {
    sumDiff += lev[i].diff;
    ans += lev[i].b + (sumDiff * lev[i].p) / 10000000.;
  }
  printf("%.10lf\n", (double)ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}