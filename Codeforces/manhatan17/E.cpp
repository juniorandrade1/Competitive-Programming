#include <bits/stdc++.h>

using namespace std;

const int N = 80;

long long pd2[N][N][N];

long long solve(int qtdBit, int qtdNum, int base) {
  if(qtdBit < 0 || qtdBit > base) return 0;
  if(qtdNum == 0) return qtdBit == 0;
  if(pd2[qtdBit][qtdNum][base] != -1) return pd2[qtdBit][qtdNum][base];
  return pd2[qtdBit][qtdNum][base] = qtdBit * solve(qtdBit - 1, qtdNum - 1, base) + (base - qtdBit) * solve(qtdBit + 1, qtdNum - 1, base);
}

int ax[N], sz;
long long pd[1 << 10][N][N][2];
int memo[1 << 10][N][N][2];
int test = 1;
int b;

long long func(int pos, int has, int under, int mask) {
  if(pos == -1) return (mask == 0 && has);
  if(__builtin_popcount(mask) > pos + 1) return 0;
  if(under && has) return solve(__builtin_popcount(mask), pos + 1, b);
  if(memo[mask][pos][has][under] == test) return pd[mask][pos][has][under];
  memo[mask][pos][has][under] = test;
  long long ret = func(pos - 1, has, under | (0 < ax[pos]), mask ^ has);
  for(int i = 1; i < b; ++i) {
    if(!under && i > ax[pos]) break;
    ret += func(pos - 1, 1, under | (i < ax[pos]), mask ^ (1 << i));
  }
  return pd[mask][pos][has][under] = ret;
}

long long solve(long x) {
  sz = 0;
  while(x) {
    ax[sz++] = (x % b);
    x /= b;
  }
  ++test;
  return func(sz - 1, 0, 0, 0);
}

int main() {
  memset(pd2, -1, sizeof pd2);
  int q; scanf("%d", &q);
  while(q--) {
    long long l, r; scanf("%d %lld %lld", &b, &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
  }
  return 0;
}