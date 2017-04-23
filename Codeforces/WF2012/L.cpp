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

const int N = 100100;

int n, m;
ll a[N], b[N];

inline void main2(int _test) {
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 0; i < m; ++i) scanf("%lld", b + i);
  sort(a, a + n);
  sort(b, b + m);
  n--; m--;
  int op = 0;
  while(n >= 0 && m >= 0) {
    if(op == 0) {
      if(n >= 1 && a[n] < b[m]) {
        a[n - 1] += a[n];
        n--;
      }
      else if(a[n] > b[m]) {
        if(n >= 1 && m >= 1 && a[n] + a[n - 1] >= b[m] + b[m - 1]) {
          a[n - 1] += a[n];
          n--;
        }
        else {
          m--;
        }
      }
    }
    else {
      if(m >= 1 && b[m] < a[n]) {
        b[m - 1] += b[m];
        m--;
      }
      else if(b[m] > a[n]) {
        if(n >= 1 && m >= 1 && b[m] + b[m - 1] >= a[n] + a[n - 1]) {
          b[m - 1] += b[m];
          m--;
        }
        else {
          n--;
        }
      }
    }
    op ^= 1;
  }
  printf("Case %d: ", _test);
  if(n < 0) puts("Buyout Limited");
  else puts("Takeover Incorporated");
}

int main() {
  int test = 1;
  while(scanf("%d %d", &n, &m) != EOF) main2(test++);
  return 0;
}