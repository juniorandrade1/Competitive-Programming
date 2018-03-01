#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 5);
const int M = (1 << 5);

int main() {
  srand(time(NULL));
  printf("%d\n", N);
  for(int i = 0; i < N; ++i) printf("%d ", 1);
  printf("\n");
  int q = M;
  printf("%d\n", q);
  while(q--) {
    printf("%d %d\n", rand() % 1000000000 + 1, 1);
  }
}