#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

typedef long long ll;

int n;
ll v[N];
ll sum, sum2, ans;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", &v[i]);
    sum += v[i];
  }
  for(int i = 0; i < n; ++i) {
    sum -= v[i];
    sum2 += v[i];
    ans = max(ans, sum * sum2);
  }
  printf("%lld\n", ans);
  return 0;
}