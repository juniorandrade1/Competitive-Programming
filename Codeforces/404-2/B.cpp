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

const int N = 2 * (1e5 + 10);

int n, m;
vii a, b;

bool cmpS(ii x, ii y) {
  if(x.S != y.S) return x.S < y.S;
  return x.F < y.F;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    ll l, r; scanf("%lld %lld", &l, &r);
    a.pb(mp(l, r));
  }
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    ll l, r; scanf("%lld %lld", &l, &r);
    b.pb(mp(l, r));
  }
  int ans = 0;

  sort(a.begin(), a.end(), cmpS);
  sort(b.begin(), b.end());


  for(int i = 0; i < b.size(); ++i) ans = max(ans, (int)(b[i].F - a[0].S));

     sort(a.begin(), a.end());
  sort(b.begin(), b.end(), cmpS);


  for(int i = 0; i < a.size(); ++i) ans = max(ans, (int)(a[i].F - b[0].S));



  printf("%d\n", ans);


  return 0;
}