#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

typedef long long ll;

int n;
vector< int > dish[N];
vector< ll > dp[N];
vector< pair<ll, ll> > go[N];

ll getLast(int i, int j) {
  return go[i][j].second;
}

ll getFirst(int i, int j) {
  return go[i][j].first;
}


inline void process(int idx) {
  go[idx].clear();
  int mn = 1234567, mx = -1234567;
  int sz = dish[idx].size();
  for(int i = 0; i < sz; ++i) {
    int v = dish[idx][i];
    mn = min(mn, v);
    mx = max(mx, v);
  }
  for(int i = 0; i < sz; ++i) {
    if(dish[idx][i] == mn) {
      go[idx].push_back(make_pair(dish[idx][i], dish[idx][(i + sz - 1) % sz]));
      go[idx].push_back(make_pair(dish[idx][(i + sz - 1) % sz], dish[idx][i]));
    }
  }
  if(mn != mx) {
    for(int i = 0; i < sz; ++i) {
      if(dish[idx][i] == mx) {
        go[idx].push_back(make_pair(dish[idx][i], dish[idx][(i + sz - 1) % sz]));
        go[idx].push_back(make_pair(dish[idx][(i + sz - 1) % sz], dish[idx][i]));
      }
    }
  }
  while(go[idx].size() < 50) {
    int i = rand() % sz;
    go[idx].push_back(make_pair(dish[idx][i], dish[idx][(i + sz - 1) % sz]));
    go[idx].push_back(make_pair(dish[idx][(i + sz - 1) % sz], dish[idx][i]));
  }
  dp[idx].resize(go[idx].size());
}

inline void main2() {
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int m; scanf("%d", &m);
    dish[i].clear();
    dp[i].clear();
    while(m--) {
      int x; scanf("%d", &x);
      dish[i].push_back(x);
    }
    process(i);
  }
  ll sol = 0;
  for(int i = 0; i + 1 < n; ++i) {
    for(int k = 0; k < dp[i + 1].size(); ++k) {
      dp[i + 1][k] = 0;
      for(int j = 0; j < dp[i].size(); ++j) {
        dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + (ll)abs(getLast(i, j) - getFirst(i + 1, k)) * (ll)(i + 1));
        sol = max(sol, dp[i + 1][k]);
      }
    }
  }
  printf("%lld\n", sol);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}