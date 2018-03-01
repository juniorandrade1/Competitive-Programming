#include <bits/stdc++.h>

using namespace std;

const int N = 101;

typedef long long ll;

ll v[N];
ll c[N][N];

int main() {
  c[0][0] = 1;
  for(int i = 1; i < N; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(j == 0 || j == i) c[i][j] = 1;
      else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      printf("%lld ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}