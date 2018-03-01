#include <bits/stdc++.h>
using namespace std;
vector< pair< int, int > > ls;
int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x0, y0; scanf("%d %d", &x0, &y0);
    if(x0 > y0) swap(x0, y0);
    ls.push_back(make_pair(x0, -1));
    ls.push_back(make_pair(y0, 1));
  }
  sort(ls.begin(), ls.end());
  int ans = 0;
  int lst = ls[0].first;
  int qtd = 0;
  for(int i = 0; i < ls.size(); ++i) {
    int x = ls[i].first;
    ans += (x - lst) * (qtd != 0);
    qtd -= ls[i].second;
    lst = x;
  }
  printf("%d\n", ans);
  return 0;
}