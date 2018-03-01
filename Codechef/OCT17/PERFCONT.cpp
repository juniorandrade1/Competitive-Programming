#include <bits/stdc++.h>

using namespace std;

inline void main2() {
  int n, p; scanf("%d %d", &n, &p);
  int qh = 0, qe = 0;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    if(x >= p / 2) qe++;
    if(x <= p / 10) qh++;
  }
  if(qe == 1 && qh == 2) puts("yes");
  else puts("no");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}