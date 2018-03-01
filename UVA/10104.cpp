#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll g = gcd(b, a % b, x1, y1);
  x = y1;
  y = (x1 - (a / b) * y1);
  return g;
}

int main() {
  ll a, b;
  while(scanf("%lld %lld", &a, &b) != EOF) {
    ll g, x, y;
    g = gcd(a, b, x, y);
    printf("%lld %lld %lld\n", x, y, g);
  }
  return 0;
}