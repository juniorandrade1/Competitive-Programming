#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (ll)1e9 + 7LL;
const int N = 2001;

inline int addMod(ll a, ll b, ll md = MOD) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline int mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

int n, h;
int v[N];
int pd[N][N];

int func(int pos, int qtd) {
  if(qtd < 0) return 0;
  if(pos == n) return qtd == 0;
  if(v[pos] + qtd < h - 1 || v[pos] + qtd > h) return 0;
  if(pd[pos][qtd] != -1) return pd[pos][qtd];
  int ret = 0;  
  if(v[pos] + qtd == h) ret = addMod(func(pos + 1, qtd), mulMod(func(pos + 1, qtd - 1), qtd));
  else {
    ret = func(pos + 1, qtd + 1);
    ret = addMod(ret, func(pos + 1, qtd));
    if (qtd) ret = addMod(ret, mulMod(func(pos + 1, qtd), qtd));
  }
  return pd[pos][qtd] = ret;
}

int main() {
  scanf("%d %d", &n, &h);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(0, 0));
  return 0;
}
