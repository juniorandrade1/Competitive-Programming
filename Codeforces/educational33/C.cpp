#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector< ll > a;
vector< int > pset;
vector< bool > visited;

int fnd(int i) { return pset[i] == i ? i : (pset[i] = fnd(pset[i])); }
void unionFind(int i, int j) {
  int fi = fnd(i), fj = fnd(j);
  if(a[fi] <= a[fj]) pset[fj] = fi;
  else pset[fi] = fj;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    a.emplace_back(x);
    pset.emplace_back(i);
    visited.emplace_back(0);
  }
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    unionFind(x, y);
  }

  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    int fi = fnd(i);
    if(visited[fi]) continue;
    ans += a[fi];
    visited[fi] = true;
  }
  printf("%lld\n", ans);



  return 0;
}