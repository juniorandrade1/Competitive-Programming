#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  int go = 3;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x); x--;
    if(!((go >> x) & 1)) {
      puts("NO");
      return 0;
    } 
    int lose = (go ^ (1 << x));
    go = ((1 << 3) - 1) ^ lose;
  }
  puts("YES");
  return 0;
}