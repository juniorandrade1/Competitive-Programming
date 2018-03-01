#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 11;
const int MOD = (int)1e9 + 7LL;

inline void addMod(int &a, int b, int md = MOD) {
  a += b;
  if(a >= md) a -= md;
}

inline int mulMod(int a, int b, int md = MOD) {
  return (1ll * a * b) % md;
}

int dp[N][M][3];
vector< int > g[N];
int n, m, k, x;

int dfs(int dad, int idx, int lstdad, int qtd, int valLst) {
  if (g[dad].size() == idx) return (qtd == 0) ? 1 : 0;
  int y = g[dad][idx];
  if (y == lstdad) return dfs(dad, idx + 1, lstdad, qtd, valLst);
  if (dp[y][qtd][valLst] != -1) return dp[y][qtd][valLst];
  int ret = 0;
  for (int i = 0; i <= qtd; ++i) {
    int s0 = mulMod(k - 1, dfs(y, 0, dad, i, 0));
    int s1 = (i == 0) ? 0 : dfs(y, 0, dad, i - 1, 1);
    int s2 = mulMod(m - k, dfs(y, 0, dad, i, 2));
    int ax = s0;
    if(valLst == 0) addMod(ax, s1);
    if(valLst != 1) addMod(ax, s2);
    ax = mulMod(ax, dfs(dad, idx + 1, lstdad, qtd - i, valLst));
    addMod(ret, ax);
  }
  return dp[y][qtd][valLst] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  scanf("%d %d", &k, &x);
  int sol = 0;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i <= x; ++i) {
    addMod(sol, mulMod(k - 1, dfs(1, 0, 1, i, 0)));
    if(i) addMod(sol, mulMod(1, dfs(1, 0, 1, i - 1, 1)));
    addMod(sol, mulMod(m - k, dfs(1, 0, 1, i, 2)));
  }
  printf("%d\n", sol);
  return 0;
}