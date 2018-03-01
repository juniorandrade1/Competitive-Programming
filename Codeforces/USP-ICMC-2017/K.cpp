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

const int N = (1 << 21) + 10;

int n, m;
ll cnt[N], pd[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    cnt[x]++;
    pd[x]++;
  }
  for(int i = 0; i < m; ++i) {
    for(int mask = 0; mask < (1 << m); ++mask) {
      if((mask >> i) & 1)
      pd[mask] += pd[mask ^ (1 << i)];
    }
  }
  ll ans = ((ll)n * (ll)(n - 1LL)) / 2LL;
  for(int i = 0; i < (1 << m); ++i) {
    ans -= (cnt[i] * (cnt[i] - 1)) / 2LL;
    ans -= (cnt[i] * (pd[i] - cnt[i]));
  }
  printf("%lld\n", ans);
  return 0;
}