#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef long long ll;

int n;
int a[N], b[N];
ll sum = 0;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum += a[i];
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  sort(b, b + n);
  if(sum <= b[n - 1] + b[n - 2]) puts("YES");
  else puts("NO");
  return 0;
}