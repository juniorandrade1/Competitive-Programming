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

const ll md = 1e9 + 7LL;

const int N = 100001;

int deg[N];
int n;
ll pw[N];

int main() {
  scanf("%d", &n);
  pw[0] = 1LL;
  for(int i = 1; i <= n; ++i) {
    pw[i] = 2LL * pw[i - 1];
    while(pw[i] >= md) pw[i] -= md;
  }
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    deg[a - 1]++;
    deg[b - 1]++;
  }
  int leaves = 0;
  for(int i = 0; i < n; ++i) leaves += (deg[i] == 1);
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += pw[n - leaves + (deg[i] == 1)];
    while(ans >= md) ans -= md;
  }
  printf("%lld\n", ans);
  return 0;
} 