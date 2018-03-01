#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef pair<int, int> ii;

int n, m;
vector< int > g[N];
int marked[N];
ii que[N];

int pset[N], setCounter;
set<int> activeSet[N];

inline void init() {
  setCounter = 1;
  for(int i = 1; i <= n; ++i) {
    g[i].clear();
    pset[i] = 0;
    marked[i] = 0;
    activeSet[i].clear();
  }
}

inline int fnd(int i) { return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }

inline void regroup(int x) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    int fx = fnd(x), fy = fnd(y);
    if(activeSet[fx].size() < activeSet[fy].size()) swap(fx, fy);
    for(set<int>::iterator it = activeSet[fy].begin(); it != activeSet[fy].end(); it++) activeSet[fx].insert(*it);
    activeSet[fy].clear();
    pset[fy] = fx;
  }
}

inline int getSecondBest(int x) {
  if(marked[x] > 0) return n - 1;
  int fx = fnd(x);
  int q = 0;
  for(int i = n; i >= 1; --i) {
    if(activeSet[fx].find(i) == activeSet[fx].end()) {
      q++;
      if(q == 2) return i;
    }
  }
  return -1;
}

void dfs(int x, int ult) {
  if(marked[x]) return;
  if(pset[x]) return;
  pset[x] = setCounter;
  activeSet[pset[x]].insert(x);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
  }
}

int sol[N];

inline void main2() {
  scanf("%d %d", &n, &m);
  init();
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 0; i < m; ++i) {
    int type, x;
    scanf("%d %d", &type, &x);
    que[i] = make_pair(type, x);
    if(type == 1) marked[x]++;
  }

  for(int i = 1; i <= n; ++i) {
    if(marked[i] > 0) {
      pset[i] = setCounter++;
      activeSet[pset[i]].insert(i);
      continue;
    }
    if(pset[i] == 0) {
      dfs(i, i);
      setCounter++;
    } 
  }

  for(int i = m - 1; i >= 0; --i) {
    int type = que[i].first, x = que[i].second;
    if(type == 1) {
      marked[x]--;
      if(!marked[x]) regroup(x);
    }
    else {
      sol[i] = getSecondBest(x);
    }
  }

  for(int i = 0; i < m; ++i) {
    int type = que[i].first, x = que[i].second;
    if(type == 2) printf("%d\n", sol[i]);
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}