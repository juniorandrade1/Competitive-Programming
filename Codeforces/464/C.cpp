#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200001;

int n;
ll v[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i), v[i + n] = v[i];
  for(int i = 1; i <= n; ++i) v[i] += v[i - 1];
  ll s, f; scanf("%lld %lld", &s, &f);
  ll ans = -1;
  ll dif = f - s;
  for(int i = dif; i <= 2 * n; ++i) ans = max(ans, v[i] - v[i - dif]);
  ll sol = n + 1;
  for(int i = dif; i <= 2 * n; ++i) {
    if(ans == v[i] - v[i - dif]) {
      int st = i - dif;
      ll foo = (n - st + s) % n;
      if(foo == 0) foo = n;
      sol = min(sol, foo);
    }
  }
  printf("%lld\n", sol);
  return 0;
}