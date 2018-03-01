#include <bits/stdc++.h>

using namespace std;


int main() {
  vector< bool > arr(32, false);
  for(int i = 0; i < 10; ++i) {
    int x; scanf("%d", &x);
    arr[x - 1] = true;
  }
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int qtd = 0;
    for(int j = 0; j < 6; ++j) {
      int x; scanf("%d", &x);
      qtd += arr[x - 1];
    }
    puts(qtd >= 3 ? "Lucky" : "Unlucky");
  }
  return 0;
}