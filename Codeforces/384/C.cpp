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

ll mmc(ll a, ll b) {
  return ((a * b)) / __gcd(a, b);
}

int main() {
  int n; scanf("%d", &n);
  if(n == 1) {
  }
  int x = n;
  ll a, b;
  for(int i = 1; i <= 50000000; ++i) {
    a = i + n;
    ll num = (a * n);
    ll den = (a - n);
    if(num % den == 0 && num / den != a && a != x && num / den != x) {
      printf("%d %lld %lld\n", x, a, num / den);
      exit(0);
    }
  }
  puts("-1");


  return 0;
}