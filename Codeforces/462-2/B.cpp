#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 60;

int n, m;

int main() {
  int k; scanf("%d", &k);
  if(k > 18 * 2) printf("-1\n");
  else {
    while(k >= 2) {
      k -= 2;
      printf("8");
    }
    if(k) printf("9");
    printf("\n");
  }
  return 0;
}