#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
const int M = 26;

char s[N], t[N];
int n;
vector< int > p[M];
int sol[N];

inline void main2(int test) {
  for(int i = 0; i < M; ++i) p[i].clear();
  scanf(" %s", s);  
  n = strlen(s);
  for(int i = 0; i < n; ++i) p[s[i] - 'a'].push_back(i);
  int q = 0;
  for(int i = 0; i < M; ++i) if((int)p[i].size() % 2 == 1) q++;
  if(q > 1) {
    printf("-1\n");
    return;
  }
  if(q == 1 && n % 2 == 0) {
    printf("-1\n");
    return;
  }
  if(q == 0 && n % 2 == 1) {
    printf("-1\n");
    return;
  }
  int l = 0, r = n - 1;
  for(int i = 0; i < 26; ++i) {
    for(int j = 0; j + 1 < p[i].size(); j += 2) {
      sol[p[i][j]] = l++;
      sol[p[i][j + 1]] = r--;
    }
    if(p[i].size() % 2 == 1) {
      int lst = p[i].size() - 1;
      sol[p[i][lst]] = (n / 2);
    }
  }
  for(int i = 0; i < n; ++i) {
    if(i) printf(" ");
    printf("%d", sol[i] + 1);
  }
  printf("\n");
  return;
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}