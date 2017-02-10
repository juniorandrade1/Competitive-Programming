#include <bits/stdc++.h>

using namespace std;

int main() {
  printf("2 10000 9999\n1\n10000\n");
  for(int i = 1; i <= 9999; ++i) {
    printf("%d %d %d\n", i, i + 1, 5000);
  }
  return 0;
}