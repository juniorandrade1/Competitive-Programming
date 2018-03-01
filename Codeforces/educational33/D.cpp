#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, d;
int v[N];
int mx[N];

int main() {
  scanf("%d %d", &n, &d);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  mx[n + 1] = 2 * d;
  for(int i = n; i >= 0; --i) {
    if(v[i] == 0) mx[i] = mx[i + 1];
    else mx[i] = min(mx[i + 1], d - v[i]);
  }

  int foo = 0;
  int qtd = 0;
  int ok = 0;
  int sol = 0;
  for(int i = 1; i <= n && !ok; ++i) {
    if(v[i] == 0) {
      if(foo >= 0) continue;
      if(-foo > mx[i + 1] - qtd) {
        ok = 1;
        break;
      }
      foo += (mx[i + 1] - qtd);
      qtd += (mx[i + 1] - qtd);
    }
    else {
      foo += v[i];
    }
  }
  if(ok) puts("-1");
  else printf("%d\n", sol);
  return 0;
}