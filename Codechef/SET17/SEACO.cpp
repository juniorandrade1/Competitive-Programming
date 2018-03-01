#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const ll mod = (ll)(1e9 + 7LL);

inline ll addMod(ll a, ll b) {
  return ((a % mod) + (b % mod) + 2LL * mod) % mod;
}

inline ll mulMod(ll a, ll b) {
  return ((a % mod) * (b % mod)) % mod;
}

int n, m;
ll v[N];
ll r[N];
int X[N], Y[N], Z[N];

inline void main2() {
  memset(v, 0, sizeof v);
  memset(r, 0, sizeof r);
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i) scanf("%d %d %d", X + i, Y + i, Z + i);
  r[m + 1] = 1;
  for(int i = m; i >= 0; --i) {
    r[i] = addMod(r[i + 1], r[i]);
    if(X[i] == 1) {
      v[Y[i]] = addMod(v[Y[i]], r[i]);
      v[Z[i] + 1] = addMod(v[Z[i] + 1], -r[i]);
    }
    else {
      r[Z[i]] = addMod(r[Z[i]], r[i]);
      r[Y[i] - 1] = addMod(r[Y[i] - 1], -r[i]);
    }
  }
  for(int i = 1; i <= n; ++i) {
    v[i] = addMod(v[i - 1], v[i]);
    printf("%lld ", v[i]);
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}