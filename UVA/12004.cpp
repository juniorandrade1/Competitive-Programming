#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    int n; scanf("%d", &n);
    long long sa = (long long)n * (long long)(n - 1LL);
    long long sb = 2;
    if(sa % 4 == 0) {
      sa /= 4;
      sb = 1;
      printf("Case %d: %lld\n", i, sa);
    }
    else {
      sa /= 2;
      printf("Case %d: %lld/%lld\n", i, sa, sb);
    }
  }
  return 0;
}