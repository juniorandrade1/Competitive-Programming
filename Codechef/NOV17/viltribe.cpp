#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int lst[2];
int c[2];
char s[N];

inline void main2() {
  scanf(" %s", s);
  int n = strlen(s);
  lst[0] = lst[1] = -1;
  c[0] = c[1] = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '.') continue;
    int op = s[i] - 'A';
    c[op]++;
    if(lst[op] > lst[op ^ 1] && lst[op] != -1) c[op] += (i - lst[op] - 1);
    lst[op] = i;
  }
  printf("%d %d\n", c[0], c[1]);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}