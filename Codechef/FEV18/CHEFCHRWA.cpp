#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000001;
 
char s[N];
 
inline void main2(int test) {
  scanf(" %s", s);
  int len = strlen(s);
  map< char, int > c;
  int qtd = 0;
  for(int i = 0; i < len; ++i) {
    c[s[i]]++;
    if(i >= 4) c[s[i - 4]]--;
    if(c['c'] == 1 && c['h'] == 1 && c['e'] == 1 && c['f'] == 1) qtd++;
  }
  if(!qtd) printf("normal\n");
  else printf("lovely %d\n", qtd);
}
 
int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}