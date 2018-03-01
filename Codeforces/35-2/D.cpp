#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector< int > v(n, 0);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  int sol = 0;
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) sol ^= (v[i] > v[j]);
  int q; scanf("%d", &q);
  while(q--) {
    int l, r; scanf("%d %d", &l, &r);
    int len = (r - l + 1);
    int s = (len * (len - 1)) / 2LL;
    sol ^= (s & 1);
    puts(sol ? "odd" : "even");
  }
  return 0;
}