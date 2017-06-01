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
const ll MOD = 1e9 + 7LL;

inline ll addMod(ll a, ll b, ll md = MOD) {
  return ((a % md) + (b % md)) % md;
}

inline ll mulMod(ll a, ll b, ll md = MOD){
  return ((a % md) * (b % md)) % md;
}

inline ll modPow(ll x, ll p, ll md = MOD) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, x);
    x = mulMod(x, x);
    p >>= 1;
  }
  return ans;
}

int p[N], sz, is[N];

inline void sieve() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
} 

int n, v[N];
map< int, int > pd[N];

int func(int pos, int atGcd) {
  if(atGcd == 1) return 1;
  if(pos == -1) return 0;
  if(pd[pos].find(atGcd) != pd[pos].end()) return pd[pos][atGcd];
  return pd[pos][atGcd] = addMod(func(pos - 1, __gcd(atGcd, v[pos])), func(pos - 1, atGcd));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  sort(v, v + n);
  ll ans = 0;
  for(int i = 0; i < n; ++i) ans = addMod(ans, func(i - 1, v[i]));
  printf("%lld\n", ans);
  return 0;
}
