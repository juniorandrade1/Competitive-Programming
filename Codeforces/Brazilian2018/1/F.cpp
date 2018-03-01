#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 45;

ll f[N];

int main() {
  f[0] = 1;
  f[1] = 2;
  for(int i = 2; i < N; ++i) f[i] = f[i - 1] + f[i - 2];
  int n, k; scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) {
    if(f[n - i] >= k) printf("0");
    else {
      printf("1");
      k -= f[n - i];
    }
  }
  printf("\n");
  return 0;
}