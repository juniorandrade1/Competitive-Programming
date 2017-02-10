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

const int N = 100010;

vi o;

bool isPrime(ll x) {
  for(int i = 0; i < o.size(); ++i) {
    if(o[i] >= x) continue;
    if(x % o[i] == 0) return false;
  }
  return true;
}

int is[N];


void crivo() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      o.pb(i);
      for(int j = 1; j * i < N; ++j) is[i * j] = 1;
    }
  }
}





int main() {
  crivo();
  ll n;
  while(scanf("%lld", &n) != EOF) {
    if(isPrime(n)) printf("%lld\n", n - 1);
    else if(isPrime(n - 2)) printf("%lld\n", n - 2);
    else if(n % 2 == 0) printf("%lld\n", n - 2);
    else printf("%lld\n", n - 3);

  }
  return 0;
}