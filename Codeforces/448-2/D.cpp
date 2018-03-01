#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (ll)1e9 + 7LL;
const int N = 1000001;
const int M = 26;

int fat[N], invFat[N], allInv[N];

inline int addMod(ll a, ll b, ll md = MOD) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline int mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

inline int powMod(ll b, ll p, int md = MOD) {
  int ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, b);
    b = mulMod(b, b);
    p >>= 1;
  }
  return ans;
}

inline int choose(int n, int k) {
  return mulMod(fat[n], mulMod(invFat[k], invFat[n - k]));
}

inline void preProcess() {
  fat[0] = invFat[0] = 1;
  for(int i = 1; i < N; ++i) {
    fat[i] = mulMod(fat[i - 1], (ll)i);
    invFat[i] = powMod(fat[i], MOD - 2);
    allInv[i] = powMod(i, MOD - 2);
  }
}

inline int solve(string s, vector< int > cnt) {
  int n = s.size();
  int cur = fat[n];
  for(int i = 0; i < M; ++i) if(cnt[i]) cur = mulMod(invFat[cnt[i]], cur);
  
  
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < s[i] - 'a'; ++j) {
      if(cnt[j]) {
	int foo = cur;
	foo = mulMod(foo, allInv[n - i]);
	foo = mulMod(foo, cnt[j]);
	ans = addMod(ans, foo);
      }
    }
    if(cnt[s[i] - 'a']) {
      cur = mulMod(cur, allInv[n - i]);
      cur = mulMod(cur, cnt[s[i] - 'a']);
      cnt[s[i] - 'a']--;
    }
    else break;
  }
  return ans;
}

char s[N], t[N];

int main() {
  preProcess();
  scanf(" %s %s", s, t);
  int n = strlen(s);
  vector< int > cnt(26, 0);
  for(int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
  printf("%d\n", addMod(solve((string)t, cnt), addMod(MOD - solve((string)s, cnt), MOD - 1))); 
  return 0;
}
