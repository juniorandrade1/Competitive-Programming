#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int n, m;
vector<int> g[N];
bool bankIsOpen[N];
 
inline void init() {
  for(int i = 0; i <= n; ++i) {
    g[i].clear();
    bankIsOpen[i] = false;
  }
}
 
set<int>q;
 
void dfs(int x, int ult, bool ok = false) {
  ok |= (bankIsOpen[x]);
  if(ok) {
    q.insert(x);
    while(q.size() > 2) q.erase(q.begin());
  }
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x, ok);
  }
}
 
inline void main2() {
  scanf("%d %d", &n, &m);
  init();
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 0; i < m; ++i) {
    int op, x; scanf("%d %d", &op, &x);
    if(op == 1 && !bankIsOpen[x]) bankIsOpen[x] = true;
    else if(op == 2) {
      q.clear();
      dfs(x, x);
      if(q.size() <= 1) puts("-1");
      else {
        set<int>::iterator it = q.end(); it--; it--;
        printf("%d\n", *it);
      }
    }
  }
  return;
}
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
} 