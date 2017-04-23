#include <bits/stdc++.h>

using namespace std;

char s[1234];

inline void main2() {
  map<string, bool>e;
  for(int i = 0; i < 4; ++i) {
    scanf(" %s", s);
    e[(string)s] = 1;
  } 
  int qtd = 0;
  for(int i = 0; i < 4; ++i) {
    scanf(" %s", s);
    qtd += e[(string)s];
  }
  puts(qtd >= 2 ? "similar" : "dissimilar");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}