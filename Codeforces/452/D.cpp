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

const int N = 10;

ll n;

int main() {
  scanf("%lld", &n);
  if(n < 5) {
    printf("%lld\n", (n * (n - 1)) / 2LL);
    return 0;
  }
  ll foo = 1;
  while(1) {
    foo *= 10;
    if(foo - 1 > n + n - 1) break;
  }
  foo /= 10;
  ll z = foo;
  foo--;
  ll ans = 0;
  for(int i = 0; i < 10; ++i) {
    ll ax = z * i + foo;
    if(ax <= n) ans += ax / 2LL;
    else ans += max((ll)0, n - ax / 2LL);
  }
  printf("%lld\n", ans);
  return 0;
}