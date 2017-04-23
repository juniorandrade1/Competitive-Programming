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

int main() {
  int n; scanf("%d", &n);
  fat[0] = 1LL;
  for(int i = 1; i <= n; ++i) fat[i] = mulMod(fat[i - 1], i);
  ll good = fat[n];
  ll bad = 0;
  for(int i = 2; i <= n; ++i) {
    ll qtdPos = n - i + 1;
    ll qtdIni = n - i + 1;
    if(i % 2 == 0) bad = addMod(bad, mulMod(qtdIni, fat[qtdPos]));
    else bad = subMod(bad, mulMod(qtdIni, fat[qtdPos]));
  }
  //printf("good = %lld bad = %lld\n", good, bad);
  ll ans = subMod(good, bad);
  printf("%lld\n", ans % md);
  return 0;
}