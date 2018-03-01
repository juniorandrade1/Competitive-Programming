#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100001;



inline void main2() {
  int n; scanf("%d", &n);
  vector< int > v;
  for(int i = 0; i < 9; ++i) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 9; ++j) {
      if(i == 0) printf("%d", v[j] < 5);
      else printf("%d", v[j] >= 5);
    }
    printf("\n");
  }
  for(int i = 0; i < 9; ++i) {
    printf("-");
    if(v[i] >= 5) v[i] -= 5;
  }
  printf("\n");
  for(int i = 0; i < 5; ++i) {
    for(int j = 0; j < 9; ++j) {
      if(i == v[j]) printf("0");
      else printf("1");
    }
    printf("\n");
  }
  printf("\n");    
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}