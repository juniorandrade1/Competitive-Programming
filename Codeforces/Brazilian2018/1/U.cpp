#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000000;

int sz = 0, p[N];
int is[N];

void sieve() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = 1;
      if(sz >= 10000) return;
    }
  }
}

int main() {
  sieve();
  int n; scanf("%d", &n);
  printf("%d\n", p[n - 1]);
  return 0;
}