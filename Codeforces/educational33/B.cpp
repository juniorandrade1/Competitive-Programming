#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll pw(ll b, ll e) {
  ll a = 1;
  for(int i = 0; i < e; ++i) a *= b;
  return a;
}

int main() {
  scanf("%d", &n);
  int sol = 1;
  for(int k = 1;; ++k) {
    int x = (pw(2, k) - 1) * (pw(2, k - 1));
    if(x > n) break;
    if(n % x == 0) {
      sol = x;
    }
  }
  printf("%d\n", sol);
  return 0;
}