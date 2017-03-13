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

const int N = 200020;

struct est {
  ll a, b;
  est(){};
  est(ll _a, ll _b) {
    a = _a;
    b = _b;
  }
  bool operator < (est other) const {
    return a - b < other.a - other.b;
  }
};

int n, k;
int a[N], b[N];
vector< est > foo;

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  for(int i = 0; i < n; ++i) scanf("%d", b + i);
  for(int i = 0; i < n; ++i) foo.pb(est(a[i], b[i]));
  sort(foo.begin(), foo.end());
  ll at = 0;
  for(int i = 0; i < n; ++i) if(i < k) at += foo[i].a; else at += foo[i].b;
  ll ans = at;
  for(int i = k; i < n; ++i) {
    at -= foo[i].b;
    at += foo[i].a;
    ans = min(ans, at);
  }
  printf("%lld\n", ans);
  return 0;
}