#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

const int N = (int)1e5 + 10;
const int MX = (int)1e9;

int n;
int v[N];
char s[N];

inline int prevIsEq(int x) {
  if(s[x - 1] == s[x - 2] && s[x - 2] == s[x - 3] && s[x - 3] == s[x - 4]) return s[x - 1] - '0';
  return -1;
}

inline int minPrev(int x) {
  int sol = MX;
  for(int i = 0; i <= 4; ++i) sol = min(sol, v[x - i]);
  return sol;
}

inline int maxPrev(int x) {
  int sol = -MX;
  for(int i = 0; i <= 4; ++i) sol = max(sol, v[x - i]);
  return sol;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  scanf(" %s", s);
  int l = -MX;
  int r = MX;
  for(int i = 4; i < n; ++i) {
    int x = prevIsEq(i);
    if(prevIsEq(i) == -1) continue;
    int mnp = minPrev(i) - 1;
    int mxp = maxPrev(i) + 1;
    if(s[i] != s[i - 1]) {
      if(s[i] == '1') {
        if(x == 0) {
          l = max(l, mxp);
        }
      }
      else {
        if(x == 1) {
          r = min(r, mnp);
        }
      } 
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}