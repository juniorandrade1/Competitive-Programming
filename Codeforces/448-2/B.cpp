#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, x, k;
int v[N];

int main() {
  scanf("%d %d %d", &n, &x, &k);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  sort(v, v + n);
  ll ans = 0; 
  for(int i = 0; i < n; ++i) {
    int has = v[i] / x;
    if(has < k) continue;
    int a = (has - k) * x;
    int b = min(v[i], (has - k + 1) * x);
    int st = lower_bound(v, v + n, a + 1) - v;
    int ed = upper_bound(v, v + n, b) - v;
    ans += (ll)ed - (ll)st;
  }
  printf("%lld\n", ans);
  return 0;
}