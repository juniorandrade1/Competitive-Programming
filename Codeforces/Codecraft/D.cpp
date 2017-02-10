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

const ll md = (ll)1e9 + 7LL;

const int N = 75;

const ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

const ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}

int n;
char s[N];

ll pd[N][1 << 17 + 1][2];

int func(int pos, int mask, int cut) {
  if(cut == 0) {
    while(mask & 1) mask >>= 1;
    return mask == 0;
  }
  if(pd[pos][mask][cut & 1] != -1) return pd[pos][mask][cut & 1];
  int ret = 0;
  int at = 0;
  for(int i = 0; i + pos < n; ++i) {
    at *= 2;
    at += (s[i + pos] - '0');
    if(at > 17) break;
    if(at == 0) continue;
    int forceBit = (1 << (at - 1));
    ret = addMod(ret, func(i + pos + 1, mask | forceBit, cut - 1));
  }
  return pd[pos][mask][cut & 1] = ret;
}

void clearState(int k) {
  for(int i = 0; i < n; ++i) for(int j = 0; j <= 1 << 17; ++j) pd[i][j][k & 1] = -1;
}

int main() {
  memset(pd, -1, sizeof pd);
  scanf("%d", &n);
  scanf(" %s", s);
  ll ans = 0;
  for(int k = 1; k < n; ++k) {
    clearState(k);
    for(int i = n - 1; i >= 0; --i) ans = addMod(ans, func(i, 0, k));
  }
  printf("%lld\n", ans);
  return 0;
}