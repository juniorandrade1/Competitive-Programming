#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector< int > v(n, 0);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  int mn = *min_element(v.begin(), v.end());
  int lst = -1;
  int sol = n;
  for(int i = 0; i < n; ++i) {
    if(v[i] != mn) continue;
    if(lst != -1) sol = min(sol, i - lst);
    lst = i;
  }
  printf("%d\n", sol);
  return 0;
}