#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector< int > g[N];
int n;
int p[N];
set< pair<int, int> > allGuys;
inline void main2() {
  scanf("%d", &n);

  for(int i = 0; i < n; ++i) g[i].clear();
  allGuys.clear();
  for(int i = 0; i < n; ++i) scanf("%d", p + i), allGuys.insert(make_pair(-p[i], i));
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 0; i < n; ++i) {
    allGuys.erase(allGuys.find(make_pair(-p[i], i)));
    for(int j = 0; j < g[i].size(); ++j) allGuys.erase(allGuys.find(make_pair(-p[g[i][j]], g[i][j])));
    if(allGuys.size() == 0) printf("0 ");
    else {
      pair<int, int> foo = *allGuys.begin();
      printf("%d ", foo.second + 1);
    }
    allGuys.insert(make_pair(-p[i], i));
    for(int j = 0; j < g[i].size(); ++j) allGuys.insert(make_pair(-p[g[i][j]], g[i][j]));
  }
  printf("\n");
}
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}