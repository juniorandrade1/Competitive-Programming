#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000001;

const ll MOD = (ll)1e9 + 7LL;

inline ll mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

inline ll addMod(ll a, ll b, ll md = MOD) {
  return ((a % md) + (b % md)) % md;
}

inline ll subMod(ll a, ll b, ll md = MOD) {
  return ((a % md) - (b % md) + 2LL * md) % md;
}

int n;
ll s[N], q[N], pd[N], pw[N];

int main() {
  pw[0] = 1LL;
  for(int i = 1; i < N; ++i) pw[i] = mulMod(pw[i - 1], 2LL);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    s[x]++;
  }
  for(int i = 1; i < N; ++i) for(int j = 1; i * j < N; ++j) q[i] += s[j * i];
  for(int i = N - 1; i >= 1; --i) {
    if(q[i] == 0) continue;
    pd[i] = mulMod(pw[q[i] - 1], q[i]);
    for(int j = 2; j * i < N; ++j) pd[i] = subMod(pd[i], pd[j * i]); 
  }
  ll ans = 0;
  for(int i = 2; i < N; ++i) ans = addMod(ans, mulMod(pd[i], i));
  printf("%lld\n", ans);
  return 0;  
}