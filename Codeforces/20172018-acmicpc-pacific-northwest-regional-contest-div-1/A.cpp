#include <bits/stdc++.h>

using namespace std;

#define debug(x...) fprintf(stderr, x)

const int N = 101;

char s[N];
int n;

inline bool solve(int i, int j) {
  while(i < j) {
    if(s[i] != s[j]) return false;
    i++; j--;
  }
  return true;
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  bool sol = false;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; j += 2) {
      sol |= solve(i, j);
    }
  }
  puts(sol == false ? "Odd." : "Or not.");
  return 0;
}