#include <bits/stdc++.h>

using namespace std;

long long mulMod(long long a, long long b, long long md) {
  return a * b % md;
}

long long addMod(long long a, long long b, long long md) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

long long powMod(long long b, long long p, long long md) {
  long long sol = 1;
  while(p) {
    if(p & 1) sol = mulMod(sol, b, md);
    p >>= 1;
    b = mulMod(b, b, md);
  }
  return sol;
}

int main() {
  long long b, n, m;
  while(scanf("%lld %lld %lld", &b, &n, &m) != EOF) {
    b %= m;
    n %= m;
    long long ib = powMod(b, m - 2, m);
    long long ax = 1;
    int sol = -1;
    for(int i = 0; i < m; ++i) {
      if(mulMod(ax, n, m) == 1) {
        sol = i;
        break;
      }
      ax = mulMod(ax, ib, m);
    }
    printf("%d\n", sol);
    /*
    int lo = 0, hi = m;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(mulMod(n, powMod(ib, md, m), m) == 1) hi = md;
      else lo = md + 1;
    }
    if(lo == m) lo = -1;
    printf("%d\n", lo);
    */
  }
  return 0;
}