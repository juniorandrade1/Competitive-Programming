#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 60;

int n, m;
ll a[N], b[N];

inline ll go(int idx) {
  ll foo = -1000000000000000001LL;
  for(int i = 0; i < n; ++i) {
    if(i == idx) continue;
    for(int j = 0; j < m; ++j) {
      foo = max(foo, a[i] * b[j]);
    }
  }
  return foo;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 0; i < m; ++i) scanf("%lld", b + i);
  ll ans = 1000000000000000001LL;
  for(int i = 0; i < n; ++i) ans = min(ans, go(i));
  printf("%lld\n", ans);
  return 0;
}