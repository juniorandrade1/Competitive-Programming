#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000;

int n;
int s[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", s + i), s[i + n] = s[i];
  int ans = 360;
  for(int i = 0; i < n; ++i) {
    int foo = 0;
    for(int j = i; j < i + n; ++j) {
      foo += s[j];
      ans = min(ans, abs(360 - 2 * foo));
    }
  }
  printf("%d\n", ans);
  return 0;
}