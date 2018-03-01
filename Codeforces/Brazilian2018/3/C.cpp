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

const int N = 251;

int n, m;
ll v[N * N];
ll a[N][N];
ll ml[N], mc[N];

int main() {
  memset(a, -1, sizeof a);
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n * m; ++i) scanf("%lld", v + i);
  if(n > m) swap(n, m);
  sort(v, v + n * m);
  int z = n * m - 1;
  for(int i = 0; i < n; ++i) {
    for(int j = i - 1; j >= 0; --j) {
      a[i][j] = v[z--];
    }
    a[i][i]= v[z--];
    for(int j = 0; j < i; ++j) {
      a[j][i] = v[z--];
    }
  }

  for(int i = n; i < m; ++i) for(int j = 0; j < n; ++j) a[j][i] = v[z--];
  assert(z != 0);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      ml[i] = max(ml[i], a[i][j]);
      mc[j] = max(mc[j], a[i][j]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i) ans += 2ll * ml[i];
  for(int i = 0; i < m; ++i) ans += 2ll * mc[i];
  printf("%lld\n", ans);
  return 0;
}