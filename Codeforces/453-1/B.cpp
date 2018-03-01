#include <bits/stdc++.h>

using namespace std;

struct Poly {
  vector< int > p;
  int n;
  Poly(){};
  Poly(int _n) {
    n = _n;
    p.resize(n + 1, 0);
  }
  Poly operator + (Poly other) const {
    int nm = max(n, other.n);
    Poly sol(nm);
    for(int i = 0; i <= n; ++i) sol.p[i] += p[i];
    for(int i = 0; i <= other.n; ++i) sol.p[i] += other.p[i];
    for(int i = 0; i <= nm; ++i) sol.p[i] %= 2;
    return sol;
  }
  Poly shift() {
    Poly sol(n + 1);
    for(int i = 0; i <= n; ++i) sol.p[i + 1] = p[i];
    return sol;
  }
  void print() {
    printf("%d\n", n);
    for(int i = 0; i <= n; ++i) {
      if(i) printf(" ");
      printf("%d", p[i]);
    }
    printf("\n");
  }
};

const int N = 151;

Poly f[N];

int main() {
  int n; scanf("%d", &n);
  f[0] = Poly(0); f[0].p[0] = 1;
  f[1] = Poly(1); f[1].p[0] = 0; f[1].p[1] = 1;
  for(int i = 2; i <= n; ++i) {
    f[i] = f[i - 1];
    f[i] = f[i].shift();
    f[i] = f[i] + f[i - 2];
  }
  f[n].print();
  f[n - 1].print();
  return 0;
}