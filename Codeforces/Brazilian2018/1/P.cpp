#include <bits/stdc++.h>

using namespace std;

void print(vector< int > ax) {
  for(int i = 0; i < ax.size(); ++i) {
    if(i) printf(" ");
    printf("%d", ax[i]);
  }
  printf("\n");
}

const int N = 100000;

int n;
vector< vector< int > > all;
int sz;
vector< int > g[N];
int vis[N];

void dfs(int x) {
  if(vis[x]) return;
  vis[x] = 1;
  print(all[x]);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(!vis[y]) {
      dfs(y);
      return;
    }
  }
}

inline void genEdge(int id) {
  vector< int > ax = all[id];
  for(int i = 0; i + 1 < ax.size(); ++i) {
    swap(ax[i], ax[i + 1]);
    int nx = lower_bound(all.begin(), all.end(), ax) - all.begin();
    g[id].push_back(nx);
    swap(ax[i], ax[i + 1]);
  }
}

int main() {
  scanf("%d", &n);
  int a[n]; 
  for(int i = 0; i < n; ++i) a[i] = i;
  do {
    vector< int > foo;
    for(int i = 0; i < n; ++i) foo.push_back(a[i] + 1);
    all.push_back(foo);
  }
  while(next_permutation(a, a + n));
  sz = all.size();
  for(int i = 0; i < sz; ++i) genEdge(i);
  dfs(0);
  return 0;
}