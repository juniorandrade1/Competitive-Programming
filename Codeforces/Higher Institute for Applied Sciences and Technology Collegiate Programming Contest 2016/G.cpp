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


const ll md = (ll)1000000007;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md; 
}


inline ll powMod(ll base, ll p) {
  ll ans = 1;
  while (p) {
    if (p & 1) ans = mulMod(ans, base);
    base = mulMod(base, base);
    p >>= 1;
  }
  return ans;
}

ll m, n;
map<ll, ll> hashMod;


inline ll go(ll x, ll sz) {
  if(x == 0) return hashMod[x] = 1;
  if(x == 1) return hashMod[x] = n;
  if(hashMod.find(x) != hashMod.end()) return hashMod[x];
  ll foo = powMod(10, sz / 2);
  ll ret = addMod(mulMod(go(x / 2, sz / 2), foo),  go(x / 2, sz / 2));
  return hashMod[x] = ret;
}

inline void main2() {
  scanf("%lld %lld", &m, &n);
  hashMod.clear();
  ll masterSize = 0;
  ll foo = n;
  while(foo) {
    masterSize++;
    foo /= 10;
  }
  for(ll i = 1; i <= 100000000000LL; i *= 2LL) go(i, i * masterSize);
  ll ans = 0;
  ll q = 0;
  ll tot = masterSize * m;
  while(m) {
    if(m & 1) {
      tot -= masterSize * (1LL << q);
      ans = addMod(ans, mulMod(hashMod[(1LL << q)], powMod(10, tot)));
    }
    q++;
    m >>= 1;
  }
  printf("%lld\n", ans);
  
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}