#include <bits/stdc++.h>

using namespace std;


inline void main2() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool ok = true;
  int mx = -1000000001, mn = 1000000001;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    if(x > m) {
      if(mn < x) ok = false;
      mn = min(mn, x);
    }
    else {
      if(x < mx) ok = false;
      mx = max(mx, x);
    }
  }
  puts(ok ? "YES" : "NO");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}