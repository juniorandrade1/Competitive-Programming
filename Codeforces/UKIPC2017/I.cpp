#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  int t; scanf("%d", &t);
  int mn = 1234567;
  int vl = -1;
  for(int i = 0; i < n; ++i) {
    if(t % a[i] < mn) {
      mn = t  % a[i];
      vl = a[i];
    }
  }
  printf("%d\n", vl);
  return 0;
}