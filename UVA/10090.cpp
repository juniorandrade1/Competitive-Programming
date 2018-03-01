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
  ll n;
  while(1) {
    scanf("%lld", &n);
    if(!n) break;
    ll n1, n2, c1, c2;
    scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
    ll x0, y0, g;
    g = gcd(n1, n2, x0, y0);
    printf("%lld\n", g);
    if(n % g != 0) {
      puts("failed");
      continue;
    }
    x0 *= (n / g);
    y0 *= (n / g);
    ll k0 = (-x0 * g) / n2;
    ll k1 = (y0 * g) / n1;

    printf("%lld %lld\n", k0, k1);

    ll x = (x0 + k0 * (n2 / g));
    ll y = (y0 - k0 * (n1 / g));
    printf("%lld %lld\n", x, y);
  }
  
  return 0;
}