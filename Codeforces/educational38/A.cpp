#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  int lst = -1;
  for(int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
      if(lst == 0) continue;
      printf("%c", c);
      lst = 0;
    }
    else {
      printf("%c", c);
      lst = -1;
    }
  }
  printf("\n");
  return 0;
}