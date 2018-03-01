#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int h[N], st[N], ed[N];
int n;

int main() {
  scanf("%d", &n);
  int maxPeriod = 0;
  for(int i = 0; i < n; ++i) scanf("%d %d %d", h + i, st + i, ed + i), maxPeriod = max(maxPeriod, h[i]);
  int hours = 0;
  while(hours < 1825 * maxPeriod) {
    int ok = 1;
    for(int i = 0; i < n && ok; ++i) {
      int foo = hours % h[i];
      int day = 0;
      if(st[i] <= ed[i]) day = (st[i] < foo && foo < ed[i]);
      else day = (foo > st[i] || foo < ed[i]);
      if(day) ok = 0;
    }
    if(ok) break;
    hours++;
  }
  if(hours == 1825 * maxPeriod) puts("impossible");
  else printf("%d\n", hours);
  return 0;
}