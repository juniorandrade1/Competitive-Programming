#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  set< int >s;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    if(x > 0) s.insert(x);
  }
  printf("%d\n", (int)s.size());
  return 0;
}