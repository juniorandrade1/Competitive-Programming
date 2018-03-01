#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);
  for(ll i = 0; i * a <= n; ++i) {
    ll xn = n - i * a;
    if(xn % b == 0) {
      puts("YES");
      printf("%lld %lld\n", i, xn / b);
      return 0;
    }
  }
  puts("NO");
  return 0; 
}