#include <bits/stdc++.h>

using namespace std;

const int N = 400002;

bitset< N > ok;

inline void main2() {
  ok.reset();
  int n; scanf("%d", &n);
  int k; scanf("%d", &k);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ok.set(x);
  }
  int s = 0;
  while(1) {
    if(ok[s] == 0) {
      if(k) {
        ok[s] = 1;
        k--;
      }
    }
    if(ok[s] == 0) break;
    s++;
  }
  printf("%d\n", s);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}