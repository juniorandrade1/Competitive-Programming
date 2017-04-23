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

ll d, n;
double k[N], s[N];

inline void preProcess() {
  for(int i = n; i >= 0; --i) {
    for(int j = i + 1; j <= n; ++j) {
      ld lo = 0, hi = s[i];
      for(int z = 0; z < 50; ++z) {
        ld mid = (lo + hi) * 0.5;
        ld t1 = (d - k[j]) / (ld)(s[j]);
        ld t2 = (d - k[i] / (ld)mid);
        if(t1 > t2) lo = mid;
        else hi = mid;
      }
      s[i] = min(s[i], lo);
    }
  }
}

inline void main2(int _test) {
  scanf("%lld %lld", &d, &n);
  s[0] = 1000000000000000000.;
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