#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char op, str[N];
int n;

inline int go() {
  int ret = 0;
  int len = strlen(str);
  for(int i = 0; i < len; ++i) ret |= (1 << (str[i] - 'a'));
  return ret;
}

inline int check(int m) {
  for(int i = 0; i < 26; ++i) if(m == (1 << i)) return true;
  return false;
}

int main() {
  scanf("%d", &n);
  int ans = 0;
  int mask = (1 << 26) - 1;
  for(int i = 0; i < n; ++i) {
    scanf(" %c", &op);
    scanf(" %s", str);
    if(op == '.') mask &= ~go();
    else {
      if(check(mask)) ans++;
      if(op == '!') mask &= go();
      else mask &= ~go();
    }
  }
  if(ans > 0) ans--;
  printf("%d\n", ans);
  return 0;
}