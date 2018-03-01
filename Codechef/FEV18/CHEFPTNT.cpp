#include <bits/stdc++.h>

using namespace std;

int n, m, x, k;

inline void main2(int test) {
  scanf("%d %d %d %d", &n, &m, &x, &k);
  int o = 0, e = 0;
  for(int i = 0; i < k; ++i) {
    char c; scanf(" %c", &c);
    if(c == 'O') o++;
    else e++;
  }
  int q = 0;
  for(int i = 1; i <= m; ++i) {
    if(i & 1) {
      q += min(o, x);
      o -= min(o, x);
    }
    else {
      q += min(e, x);
      e -= min(e, x);
    }
  }  
  puts(q >= n ? "yes" : "no");
  return;
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}