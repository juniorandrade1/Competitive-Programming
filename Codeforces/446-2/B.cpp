#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef long long ll;

int n;
int c[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    c[max(0, i - x)]++;
    c[i]--;
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    c[i] += c[i - 1];
    ans += (c[i] == 0);
  }
  printf("%d\n", ans);
  return 0;
}