#include <bits/stdc++.h>

using namespace std;

int main() {
  int x; scanf("%d", &x);
  for(int i = 0; i < 26; ++i) {
    int cnt = 1;
    while((cnt * (cnt + 1)) <= x * 2) cnt++;
    x -= ((cnt * (cnt - 1)) / 2LL);
    for(int j = 0; j < cnt; ++j) printf("%c", i + 'a');
  }
  printf("\n");
  return 0;
}