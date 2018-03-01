#include <bits/stdc++.h>

using namespace std;

int n = 10;
int m = 10;
int t = 1;

int main() {
  srand(time(NULL));
  printf("%d\n", t);
  while(t--) {
    printf("%d %d\n", n, m);
    for(int i = 0; i + 1 < n; ++i) {
      printf("%d %d\n", i + 1, i + 2);
    }
    for(int i = 0; i < m; ++i) {
      int op = rand() % 2 + 1;
      int x = rand() % n + 1;
      printf("%d %d\n", op, x);
    }
  }
  return 0;
}