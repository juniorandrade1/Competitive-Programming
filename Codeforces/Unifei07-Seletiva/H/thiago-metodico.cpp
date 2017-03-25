#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1001;

int n, m;
ll v[N][N];

int main() {
  scanf("%d %d", &n, &m);
  ll maxi = 0x3f3f3f3f3f3f3fLL;
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    scanf("%lld", &v[i][j]);
    if(v[i][j]) maxi = min(maxi, v[i][j]);
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(v[i][j]) ans += v[i][j] - maxi;
  printf("%lld\n", ans);
  return 0;
}