#include <bits/stdc++.h>

using namespace std;

string s;

inline int go(int l, int r) {
  map< char, int > ax;
  for(int i = l; i <= r; ++i) ax[s[i]]++;
  return ax['c'] == 1 && ax['h'] == 1 && ax['e'] == 1 && ax['f'] == 1;
}

inline void main2(int test) {
  cin >> s;
  int qtd = 0;
  for(int i = 0; i + 4 <= s.size(); ++i) {
    qtd += go(i, i + 3);
  }
  if(qtd == 0) cout << "normal\n";
  else cout << "lovely " << qtd << endl;
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}