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
#define eps 1e-8


int main() {
  int r, d; scanf("%d %d", &r, &d);
  d = r - d;
  int n; scanf("%d", &n);
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    int xi, yi, ri; scanf("%d %d %d", &xi, &yi, &ri);
    double foo = hypot(yi, xi);
    bool insideR = (foo + ri) < r - eps;
    bool insideD = (foo + ri) < d + eps || foo < d + eps;
    cnt += (insideR && !insideD);
  }
  printf("%d\n", cnt);
  return 0;
}