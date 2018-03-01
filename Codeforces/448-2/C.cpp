#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7LL;

inline int addMod(ll a, ll b, ll md = MOD) {
  return ((a % md) + (b % md)) % md;
}

inline int mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

const int P = 19;
const int N = 100010;
const int M = 71;

int n;
int cnt[M];
int preMask[M];
int pow2[N];
int is[M];
int idxP[M];

inline void preprocess() {
  pow2[0] = 1;
  for(int i = 1; i < N; ++i) {
    pow2[i] = addMod(pow2[i - 1], pow2[i - 1]);
  }

  int cp = 0;
  for(int i = 2; i < M; ++i) {
    if(is[i] == 0) {
      idxP[i] = cp++;
      for(int j = 1; i * j < M; ++j) is[i * j] = i;
    }
  }
  for(int i = 2; i < M; ++i) {
    int x = i;
    while(x > 1) {
      preMask[i] ^= (1 << (idxP[is[x]]));
      x /= is[x];
    }
  }
}

int pd[M][1 << P];

int func(int pos, int mask) {
  if(pos == 71) return mask == 0;
  if(pd[pos][mask] != -1) return pd[pos][mask];
  int ret = 0;
  if(cnt[pos] == 0) ret = func(pos + 1, mask);
  else ret = mulMod(pow2[cnt[pos] - 1], addMod(func(pos + 1, mask), func(pos + 1, mask ^ preMask[pos])));
  return pd[pos][mask] = ret;
}

int main() {
  preprocess();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    cnt[x]++;
  }
  memset(pd, -1, sizeof pd);
  printf("%d\n", addMod(func(1, 0), MOD - 1));
  return 0;
}
