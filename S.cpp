#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll g[26][26];
char s[1234567];

int main() {
  for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) {
    scanf("%lld", &g[i][j]);
  }
  for(int k = 0; k < 26; ++k) for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  scanf(" %s", s);
  int n = strlen(s);
  ll sol = 0;
  for(int i = 0; i < n / 2; ++i) {
    ll mn = 100000000000000LL;
    int j = n - i - 1;
    for(int k = 0; k < 26; ++k) mn = min(mn, g[s[i] - 'a'][k] + g[s[j] - 'a'][k]);
    sol += mn;
  }
  printf("%lld\n", sol);
  return 0;
}