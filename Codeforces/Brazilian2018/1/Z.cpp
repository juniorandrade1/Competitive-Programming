#include <bits/stdc++.h>

int n;

bool ok(int x) {
  int q = 0;
  for(int i = n - 1; i >= 0; --i) {
    if((x >> i) & 1) {
      if(q == 0) return false;
      q--;
    }
    else q++;
  }
  return q == 0;
}

void print(int x) {
  for(int i = n - 1; i >= 0; --i) {
    if((x >> i) & 1) printf(")");
    else printf("(");
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  n *= 2;
  for(int i = 0; i < (1 << n); ++i) {
    if(ok(i)) print(i);
  }
  return 0;
}