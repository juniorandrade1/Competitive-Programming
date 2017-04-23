#include <bits/stdc++.h>

#define pq priority_queue

using namespace std;

char s[1234567];
int need[1234567];
int n;

inline void main2() {
  scanf(" %s", s);
  n = strlen(s);
  while(n && s[n - 1] == '1') n--;
  long long ans = 0;
  long long qtd = 1;
  long long need = n - 1;
  for(int i = n - 1; i >= 0; --i) if(s[i] == '1') {
    if(s[i + 1] == '1') qtd--;
    ans += (need - i) + qtd;
    need--;
    qtd++;
  }
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}