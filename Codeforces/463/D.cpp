#include <bits/stdc++.h>

using namespace std;

#define INF (int)1e9 + 1
#define LINF (ll)1e18 + 1

typedef long long ll;

const int N = 400022;
const int M = 20;

ll lca[N][M], sum[N][M], w[N];
int cnt = 1;

inline void insertNode(int p, ll v) {
  int x = cnt++;
  w[x] = v;
  if(w[p] >= w[x]) lca[x][0] = p;
  else {
    for(int i = M - 1; i >= 0; --i) {
      if(w[lca[p][i]] < w[x]) p = lca[p][i];
    }
    lca[x][0] = lca[p][0];
  }
  sum[x][0] = w[x];
  for(int i = 1; i < M; ++i) {
    lca[x][i] = lca[lca[x][i - 1]][i - 1];
    if(sum[x][i - 1] == LINF || sum[lca[x][i - 1]][i - 1] == LINF) sum[x][i] = LINF;
    else sum[x][i] = sum[x][i - 1] + sum[lca[x][i - 1]][i - 1];
  }
}

inline ll solve(ll x, ll v) {
  ll ans = 0;
  for(int i = M - 1; i >= 0; --i) {
    if(sum[x][i] <= v) {
      ans += (1 << i);
      v -= sum[x][i];
      x = lca[x][i];
    }
  }
  return ans;
}

int main() {
  w[0] = INF;
  for(int i = 0; i < M; ++i) sum[0][i] = LINF;
  insertNode(0, 0);
  int q; scanf("%d", &q);
  ll last = 0;
  while(q--) {
    int op; scanf("%d", &op);
    ll x, y; scanf("%lld %lld", &x, &y);
    x ^= last;
    y ^= last;
    if(op == 1) {
      insertNode(x, y);
    }
    else {
      last = solve(x, y);
      printf("%lld\n", last);
    }
  }
  return 0;
}