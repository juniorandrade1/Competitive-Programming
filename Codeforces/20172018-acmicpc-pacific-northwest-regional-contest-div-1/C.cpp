#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000001;

int isDiv[N];
ll p[N], sz = 0;

void sieve() {
  for(int i = 2; i < N; ++i) {
    if(isDiv[i] == 0) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) isDiv[i * j] = i;
    }
  }
}

inline ll solve(ll x) {
  ll ans = 0;
  for(int i = 0; i < sz && x >= N; ++i) {
    if(p[i] * p[i] > x) break; 
    while(x % p[i] == 0) {
      ans += p[i];
      x /= p[i];
    }
  }
  if(x > N) {
    ans += x;
    x = 1;
  }
  while(x > 1) {
    ans += isDiv[x];
    x /= isDiv[x];
  }
  return ans;
}

int main() {
  sieve();
  ll a, b; scanf("%lld %lld", &a, &b);
  ll ans = 0;
  for(ll i = a; i <= b; ++i) ans += solve(i);
  printf("%lld\n", ans);
  return 0;
}