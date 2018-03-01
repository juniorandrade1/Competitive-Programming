#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 101;

int n, d;
int v[N];

int main() {
  scanf("%d %d", &n, &d);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  sort(v, v + n);
  int ans = n - 1;
  int j = 0;
  for(int i = 0; i < n; ++i) {
    while(j < n && v[j] - v[i] <= d) j++;
    ans = min(ans, n - (j - i));
  }
  printf("%d\n", ans);
  return 0;
}