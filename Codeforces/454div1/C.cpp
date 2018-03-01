#include <bits/stdc++.h>

using namespace std;

const int N = 22;

#define INF 0x3f3f3f3f

int n, m;
int mk[N];
int dis[(1 << N)];
pair<int, int> dad[(1 << N)];

void bfs() {
  for(int i = 0; i < (1 << N); ++i) {
    dis[i] = INF;
    dad[i] = make_pair(-1, -1);
  }
  queue< int > q;
  for(int i = 0; i < n; ++i) {
    q.push(mk[i]);
    dis[mk[i]] = 1;
    dad[mk[i]] = make_pair(-1, i);
  }
  while(!q.empty()) {
    int mask = q.front(); q.pop();
    for(int i = 0; i < n; ++i) {
      if(!((mask >> i) & 1)) continue;
      int nmask = (mask | mk[i]);
      if(dis[nmask] > dis[mask] + 1) {
        dis[nmask] = dis[mask] + 1;
        dad[nmask] = make_pair(mask, i);
        q.push(nmask);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) mk[i] = (1 << i);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    mk[a] |= (1 << b);
    mk[b] |= (1 << a);
  }
  if(m == (n * (n - 1)) / 2LL) {
    puts("0");
    return 0;
  }
  bfs();
  printf("%d\n", dis[(1 << n) - 1]);
  vector< int > sol;
  int lst = (1 << n) - 1;
  while(lst != -1) {
    sol.push_back(dad[lst].second + 1);
    lst = dad[lst].first;
  }
  reverse(sol.begin(), sol.end());
  for(int i = 0; i < (int)sol.size(); ++i) {
    if(i) printf(" ");
    printf("%d", sol[i]);
  }
  printf("\n");
  return 0;
}