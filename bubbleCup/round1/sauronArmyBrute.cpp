#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll md = (ll)(1e9 + 7LL);

inline ll addMod(ll a, ll b, ll MOD = md) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

inline ll mulMod(ll a, ll b, ll MOD = md) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

inline ll subMod(ll a, ll b, ll MOD = md) {
  a %= MOD;
  b %= MOD;
  a -= b;
  while(a < 0) a += MOD;
  return a;
}

const int N = 502;

ll fat[N];
ll v[N];
int n;

int ok() {
  for(int i = 0; i + 1 < n; ++i) {
    if(v[i] + 1 == v[i + 1]) return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) v[i] = i;
  int ans = 0;
  do {
    ans += ok();
  }
  while(next_permutation(v, v + n));
  printf("%d\n", ans);
  return 0;
}