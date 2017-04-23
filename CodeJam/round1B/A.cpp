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

const int N = 1010;

double d;
int n;
double k[N], s[N];

inline double solve(int a, int b) {
  double lo = 0, hi = s[a];
  for(int i = 0; i < 500; ++i) {
    double mid = (lo + hi) * 0.5;
    double t1 = (d - k[a]) / mid;
    double t2 = (d - k[b]) / s[b];
    if(t1 > t2) lo = mid;
    else hi = mid;
  }
  return lo;
}

inline void preProcess() {
  for(int i = n - 1; i >= 0; --i) for(int j = i + 1; j <= n; ++j) s[i] = min(s[i], solve(i, i + 1));
}

inline void main2(int _test) {
  scanf("%lf %d", &d, &n);
  s[0] = 1000000000000000000000.;
  k[0] = 0;
  for(int i = 1; i <= n; ++i) scanf("%lf %lf", k + i, s + i);
  preProcess();
  printf("Case #%d: %.10lf\n", _test, s[0]);
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}