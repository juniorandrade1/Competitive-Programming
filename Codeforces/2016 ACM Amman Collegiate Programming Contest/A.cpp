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

const int N = 150;
const int M = 15100;

const ll md = (1e9 + 7LL);

ll a[N], b[N];
int n, m, k, w;

inline ll addMod(ll a, ll b) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}

ll pa[M], pb[M];


inline void main2() {
  scanf("%d %d %d %d", &n, &m, &k, &w);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 0; i < m; ++i) scanf("%lld", b + i);
  for(int i = 0; i <= w; ++i) pa[i] = pb[i] = 0;
  pa[0] = pb[0] = 1;
  for(int i = 0; i < n; ++i) for(int j = w; j >= a[i]; --j) pa[j] = addMod(pa[j], pa[j - a[i]]);
  for(int i = 0; i < m; ++i) for(int j = w; j >= b[i]; --j) pb[j] = addMod(pb[j], pb[j - b[i]]);
  ll ans = 0;
  for(int i = 0; i <= w; ++i) {
    int f = abs(w - i);
    if(abs(f - i) > k) continue;
    ans = addMod(ans, mulMod(pa[i], pb[f]));
  }
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}