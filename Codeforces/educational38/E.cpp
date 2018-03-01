#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000001;
const ll MOD = (ll)1e9 + 7LL;

ll fat[N], inv[N];

inline ll addMod(ll a, ll b, ll md = MOD) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b, ll md = MOD) {
  return (a * b) % md;
}

inline ll subMod(ll a, ll b, ll md = MOD) {
  a -= b;
  while(a < 0) a += md;
  return a;
}

inline ll powMod(ll x, ll p) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, x);
    p >>= 1;
    x = mulMod(x, x);
  }
  return ans;
}

inline void preprocess() {
  fat[0] = inv[0] = 1;
  for(int i = 1; i < N; ++i) {
    fat[i] = mulMod(fat[i - 1], i);
    inv[i] = powMod(i, MOD - 2);
  }
}

int main() {
  preprocess();
  int n; scanf("%d", &n);
  map< int, int > c;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    c[x]++;
  }
  int small = 0;
  ll ans = 0;
  ll lst = 0;
  for(auto it : c) {
    int larger = n - small;
    ll foo = it.first;
    foo = mulMod(foo, fat[n]);
    foo = mulMod(foo, it.second);
    foo = mulMod(foo, inv[larger]);
    ans = addMod(ans, foo);
    small += it.second;
    lst = it.first;
  }
  ans = subMod(ans, mulMod(fat[n], lst));
  printf("%lld\n", ans);
  return 0;
}