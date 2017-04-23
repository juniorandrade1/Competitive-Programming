#include <stdio.h>
#include <stdlib.h>

const int N = 100010;

int n, l, r;
int a[100010], b[100010];
int cntA[123456], cntB[123456];

int solve() {
  for(int i = 1; i < l; ++i) if(a[i] != b[i]) return 0;
  for(int i = r + 1; i <= n; ++i) if(a[i] != b[i]) return 0;
  for(int i = l; i <= r; ++i) {
    cntA[a[i]]++;
    cntB[b[i]]++;
  }
  for(int i = 0; i < 123456; ++i) if(cntA[i] != cntB[i]) return 0;
  return 1;
}

int main() {
  scanf("%d %d %d", &n, &l, &r);
  for(int i = 1; i <= n; ++i) scanf("%d", a + i);
  for(int i = 1; i <= n; ++i) scanf("%d", b + i);
  if(solve() == 0) puts("LIE");
  else puts("TRUTH");
  return 0;
}