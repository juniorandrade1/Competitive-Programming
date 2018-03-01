#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll gcd(ll a, ll b) {
  return (!a) ? b : gcd(b % a, a);
}

ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int n; scanf("%d", &n);
  ll ans = 1;
  for(int i = 2; i <= n; ++i) {
    ans = lcm(ans, i);
  }
  printf("%lld\n", ans);
  return 0;
}