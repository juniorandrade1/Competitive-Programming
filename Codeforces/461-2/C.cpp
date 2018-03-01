#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10000100;

ll n, k;
int c[N];

int main() {
  scanf("%lld %lld", &n, &k);
  if(k > n + 1) {
    puts("No");
    return 0;
  }
  k = min(k, (ll)N - 1);
  for(int i = 1; i <= k; ++i) {
    c[n % i]++;
    if(c[n % i] > 1) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}