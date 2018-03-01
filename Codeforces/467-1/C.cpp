#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

int n;
char s[N], t[N];
int fq[26];

inline void go(int x, vector< int > &solution) {
  solution.push_back(x);
  string alpha = string(s, s + n - x);
  string beta = string(s + n - x, s + n);
  reverse(beta.begin(), beta.end());
  for(int i = 0; i < beta.size(); ++i) s[i] = beta[i];
  for(int i = 0; i < alpha.size(); ++i) s[i + (int)beta.size()] = alpha[i];
}

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  scanf(" %s", t);
  for(int i = 0; i < n; ++i) {
    fq[s[i] - 'a']++;
    fq[t[i] - 'a']--;
  }
  for(int i = 0; i < 26; ++i) {
    if(fq[i]) {
      puts("-1");
      return 0;
    }
  }
  vector< int > solution;
  for(int i = 0; i < n; ++i) {
    int fo = i;
    while(fo < n && s[fo] != t[n - i - 1]) fo++;
    go(n, solution);
    go(fo, solution);
    go(1, solution);
  }
  printf("%d\n", (int)solution.size());
  for(int i = 0; i < (int)solution.size(); ++i) {
    if(i) printf(" ");
    printf("%d", solution[i]);
  }
  printf("\n");
  return 0;
}