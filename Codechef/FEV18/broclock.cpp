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
#define eps 1e-6

const ll md = (ll)1e9 + 7LL;
const int M = 2;

inline ll mulMod(ll a, ll b, ll MOD = md) {
  return (a * b) % MOD;
}

inline ll addMod(ll a, ll b, ll MOD = md) {
  return (a + b) % MOD;
}

inline ll fastExp(ll x, ll t, ll MOD = md) { 
  ll ret = 1;
  while(t) { 
    if(t & 1) ret = mulMod(ret, x, MOD);
    x = mulMod(x, x, MOD);
    t >>= 1;
  }
  return ret;
}

inline ll invMod(ll a) {
  return fastExp(a, md - 2);
}

struct Matriz {
  ll v[M][M];
  Matriz(){
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) v[i][j] = 0;
  };
  Matriz operator * (Matriz other) const {
    Matriz ans;
    for(int k = 0; k < M; ++k) for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) ans.v[i][j] = addMod(ans.v[i][j], mulMod(v[i][k], other.v[k][j]));
    return ans;
  }
  Matriz operator ^ (ll p) const {
    Matriz sol; for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) sol.v[i][j] = (i == j) ? 1 : 0;
    Matriz base; for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) base.v[i][j] = v[i][j];
    while(p) {
      if(p & 1) sol = sol * base;
      base = base * base;
      p >>= 1;
    }
    return sol;
  }
};


inline void main2() {
  ll l, d, t; scanf("%lld %lld %lld", &l, &d, &t);
  ll cos = mulMod(d, invMod(l));
  ll cos2 = mulMod(2, cos);
  Matriz foo; 
  foo.v[0][0] = cos2;
  foo.v[0][1] = md - 1;
  foo.v[1][0] = 1;
  foo.v[1][1] = 0;
  foo = foo ^ (t - 1);
  ll cans = addMod(mulMod(foo.v[0][0], cos), foo.v[0][1]);
  ll ans = mulMod(cans, l);
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
} 