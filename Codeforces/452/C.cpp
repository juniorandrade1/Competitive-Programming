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

const int N = 60010;

ll n;

int main() {
  scanf("%lld", &n);
  ll tot = ((n * (n + 1LL)) / 4LL);
  ll ga = 0, gb = 0;
  vi sol;
  for(int i = n; i >= 1; --i) {
    if(i <= tot) {
      tot -= i;
      ga += i;
      sol.pb(i);
    }
    else gb += i;
  }
  sort(sol.begin(), sol.end());
  if(ga < gb) swap(ga, gb);
  ll ans = ga - gb;
  printf("%lld\n%d", ans, (int)sol.size());
  for(int i = 0; i < (int)sol.size(); ++i) printf(" %lld", sol[i]);
  printf("\n");
  return 0;
}