#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  vector< int > ct(1501, 0);
  ct[a]++; ct[b]++; ct[c]++;
  puts(ct[1] >= 1 || ct[2] >= 2 || ct[3] >= 3 || (ct[2] == 1 && ct[4] == 2) ? "YES" : "NO");
  return 0;
}