#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector< int > v(n);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    ans = max(ans, min(v[i] - 1, 1000000 - v[i]));
  }
  
  printf("%d\n", ans);
  return 0;
}