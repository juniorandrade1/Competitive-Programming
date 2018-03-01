#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m;
vector< pair<ll, ll> > g[N];
ll dp[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    ll x, y, w; scanf("%lld %lld %lld", &x, &y, &w);
    g[x].push_back(make_pair(y, w));
    g[y].push_back(make_pair(x, w));
  }
  priority_queue< pair<ll, ll> > q;
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", dp + i);
    q.push(make_pair(-dp[i], i));
  }
  while(!q.empty()) {
    pair<ll, ll> foo = q.top(); q.pop();
    int x = foo.second;
    ll w = -foo.first;
    if(dp[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].first;
      ll c = g[x][i].second * 2LL;
      if(dp[y] > dp[x] + c) {
        dp[y] = dp[x] + c;
        q.push(make_pair(-dp[y], y));
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(i != 1) printf(" ");
    printf("%lld", dp[i]);
  }
  return 0;
}