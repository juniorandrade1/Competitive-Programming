#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

typedef long long ll;

int n;
ll v[N], l, r;

ll solve(ll x) {
  ll ans = 0;
  for(int i = n - 2; i >= 0; --i) {
    ll high = v[i] + v[n - 1] - 1;
    ll lower = v[n - 1] - v[i] + 1;
    if(high >= x && lower <= x) {
      ans += x - lower + 1;
      x = lower - 1;
    }
  }
  for(int i = n - 1; i > 0; --i) {
    ll high = v[i] + v[0] - 1;
    ll lower = v[i] - v[0] + 1;
    if(high >= x && lower <= x) {
      ans += x - lower + 1;
      x = lower - 1;
    }
  }
  return ans;
}

int main() {
  scanf("%d %lld %lld", &n, &l, &r);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  printf("%lld\n", solve(r) - solve(l - 1));
  return 0;
}