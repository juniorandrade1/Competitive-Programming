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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}


int main() {
  //arquivo();
  ll n, x, y;
  scanf("%lld %lld %lld", &n, &x, &y);
  ll lo = 0, hi = 1000000000000000000LL;
  while(lo < hi) {
    ll mid = (lo + hi) >> 1LL;
    ll q = mid / x + mid / y;
    if(q < n) lo = mid + 1;
    else hi = mid;
  }
  printf("%lld\n", lo);
  return 0;
}