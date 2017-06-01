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

const int N = 1e5 + 10;

ll n, k;


int main() {
  scanf("%lld %lld", &n, &k);
  if(k >= 100000) puts("-1");
  else {
    ll mn = (k * (k + 1)) / 2LL;
    if(mn > n) {
      puts("-1");
      exit(0);
    }
    if(mn == n) {
      for(int i = 1; i <= k; ++i) printf("%d ", i);
      printf("\n");
      exit(0);
    }

    for(int i = 0; i < k; ++i) {

    }
  }
  return 0;
}
