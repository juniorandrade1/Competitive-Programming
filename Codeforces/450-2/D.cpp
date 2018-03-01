#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7LL;

const int N = 100001;

inline int addMod(int a, int b, int md = MOD) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

inline int subMod(int a, int b, int md = MOD) {
  a -= b;
  if(a < 0) a += md;
  return a;
}

inline int mulMod(int a, int b, int md = MOD) {
  return (1ll * a * b) % md;
}

inline int powMod(int b, int p, int md = MOD) {
  int ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, b);
    b = mulMod(b, b);
    p >>= 1;
  }
  return ans;
}

int p[N], sz = 0;
int dt[N];

inline void crivo() {
  for(int i = 2; i < N; ++i) {
    if(!dt[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) if(dt[i * j] == 0) dt[i * j] = i;
    }
  }
}

vector< pair<int, int> > factorize(int x) {
  vector< pair<int, int> > sol;
  for(int i = 0; i < sz; ++i) {
    if(p[i] > x) break;
    if(x % p[i] == 0) {
      int q = 0;
      while(x % p[i] == 0) {
        x /= p[i];
        q++;
      }
      sol.push_back(make_pair(p[i], q));
    }
  }
  if(x > 1) sol.push_back(make_pair(x, 1));
  return sol;
}

void backDivisors(int pos, int foo, vector< pair<int, int > > &f, vector< int > &sol) {
  if(pos == f.size()) {
    if(foo > 1) sol.push_back(foo);
    return;
  }
  int ax = 1;
  for(int i = 0; i <= f[pos].second; ++i) {
    backDivisors(pos + 1, foo * ax, f, sol);
    ax *= f[pos].first;
  }
}

vector< int > getDivisors(int x) {
  vector< pair<int, int> > f = factorize(x);
  vector< int > sol; backDivisors(0, 1, f, sol);
  return sol;
}

map< int, int > pd;

int func(int t) {
  if(pd.find(t) != pd.end()) return pd[t];
  if(t == 1) return 1;
  int ret = powMod(2, t - 1);
  vector< int > g = getDivisors(t);
  for(int i = 0; i < g.size(); ++i) ret = subMod(ret, func(t / g[i]));
  return pd[t] = ret;
}

int main() {
  crivo();
  int x, y; scanf("%d %d", &x, &y);
  if(y % x != 0) {
    puts("0");
    return 0;
  }
  printf("%d\n", func(y / x));
  return 0;
}