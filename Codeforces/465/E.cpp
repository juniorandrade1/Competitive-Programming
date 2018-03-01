#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f3f3f3f3fLL

const int N = 10010;

int isPlusDP;
char s[N];
int pr[N];
int n;
bool memo[N][101][2];
ll dp[N][101][2];

ll func(int posL, int plus, int type) {
  if(s[posL] != '(') return (plus == 0) ? s[posL] - '0' : ((type == 1) ? -INF : INF);
  if(memo[posL][plus][type]) return dp[posL][plus][type];
  memo[posL][plus][type] = 1;
  ll ret = (type == 1) ? -INF : INF;
  int posI = pr[posL], qtd;
  qtd = plus - isPlusDP;
  for(int i = 0; i <= qtd; ++i) {
    if(type) ret = max(ret, func(posL + 1, i, type) + func(posI + 1, qtd - i, type));
    else ret = min(ret, func(posL + 1, i, type) + func(posI + 1, qtd - i, type));
  }
  qtd = plus - (1 - isPlusDP);
  for(int i = 0; i <= qtd; ++i) {
    if(type) ret = max(ret, func(posL + 1, i, type) - func(posI + 1, qtd - i, type ^ 1));
    else ret = min(ret, func(posL + 1, i, type) - func(posI + 1, qtd - i, type ^ 1));
  }
  return dp[posL][plus][type] = ret;
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  int p, m; scanf("%d %d", &p, &m);
  isPlusDP = (p <= m);
  stack< int > st;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')') st.pop();
    else if(s[i] == '?') pr[st.top()] = i;
  }
  printf("%lld\n", func(0, min(p, m), 1));
  return 0;
}