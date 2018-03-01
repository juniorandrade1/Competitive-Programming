#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000001;

ll is[N], p[N], sz = 0;

void sieve() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
}

vector< pair< ll, ll > > factorize(ll x) {
  vector< pair<ll, ll> > ct;
  for(int i = 0; i < sz; ++i) {
    if(p[i] * p[i] > x) break;
    int q = 0;
    while(x % p[i] == 0) {
      x /= p[i];
      q++;
    }
    if(q > 0) ct.push_back(make_pair(p[i], q));
  }
  if(x > 1) ct.push_back(make_pair(x, 1));
  return ct;
}

void getDivisors(int pos, ll val, vector< pair<ll, ll> > &f, vector< ll > &s) {
  if(pos == f.size()) {
    s.push_back(val);
    return;
  }
  for(int i = 0; i <= f[pos].second; ++i) {
    getDivisors(pos + 1, val, f, s);
    val *= f[pos].first;
  }
  return;
}

unordered_map< ll, ll > sol;

inline void go(ll x) {
  vector< pair< ll, ll > > fac = factorize(x);
  vector< ll > div; getDivisors(0, 1, fac, div);
  for(int i = 0; i < div.size(); ++i) {
    ll y = div[i];
    if(sol.find(y) == sol.end()) sol[y] = x;
    else sol[y] = min(sol[y], x);
  }
}

inline void preprocess() {
  sieve();
  for(int i = 1; i < (1 << 12); ++i) {
    long long ans = 0;
    for(int j = 0; j < 12; ++j) {
      ans *= 10LL;
      ans += ((i >> j) & 1);
    }
    go(ans);
  }
}

int main() {
  preprocess();
  ll n;
  while(scanf("%lld", &n) != EOF) {
    if(sol.find(n) != sol.end()) printf("%lld\n", sol[n]);
    else printf("-1\n");
  }
  return 0;
}