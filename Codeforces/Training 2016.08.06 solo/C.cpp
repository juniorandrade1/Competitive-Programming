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

const int N = 202;

const ll md = 1e9 + 7LL;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

int n, m;
ll pd[N][N];

ll func(int pos, int lst) {
  if(pos == n) return 1;
  if(pd[pos][lst] != -1) return pd[pos][lst];
  ll ret = 0;
  for(int i = lst + 1; i < m; ++i) ret = addMod(ret, func(pos + 1, i));
  return pd[pos][lst] = ret;
}

int main() {
  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  memset(pd, -1, sizeof pd);
  ll ans = 0;
  for(int i = 0; i < m; ++i) ans = addMod(ans, func(1, i));
  printf("%lld\n", ans);
  return 0;
}