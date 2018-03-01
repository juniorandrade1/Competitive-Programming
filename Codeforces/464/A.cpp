#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5050;

int n;
int f[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", f + i);
  for(int i = 1; i <= n; ++i) {
    if(f[f[f[i]]] == i) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}