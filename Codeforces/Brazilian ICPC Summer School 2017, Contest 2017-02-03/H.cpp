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

const int N = 1e5 + 10;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

ll s, m, p;

inline bool f(double x) {
  double sl = s;
  double bs = 0;
  for(int i = 1; i <= m; ++i) {
    double a1 = sl * (double)p / 100.;
    bs += x - a1;
    sl -= (x - a1);
  }
  return bs <= s;
}

int main() {
  arquivo();
  scanf("%lld %lld %lld", &s, &m, &p);
  double lo = 0, hi = 10000000000000.;
  for(int i = 0; i < 1000; ++i) {
    double mid = (lo + hi) * 0.5;
    if(f(mid)) lo = mid;
    else hi = mid;
  }
  printf("%.5lf\n", lo);
  return 0;
}