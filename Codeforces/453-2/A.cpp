#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; scanf("%d %d", &n, &m);
  int st = 0;
  for(int i = 0; i < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    if(a <= st) st = max(st, b);
  }
  puts(st >= m ? "YES" : "NO");
  return 0;
}