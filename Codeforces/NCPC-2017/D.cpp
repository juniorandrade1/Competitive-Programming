#include <bits/stdc++.h>

using namespace std;

const int N = 2000001;
const int INF = 0x3f3f3f3f;

int n, k;
int a[N];
queue<int>q;
int dis[N];

inline void bfs() {
  while(!q.empty()) {
    int x = q.front(); q.pop();
    for(int i = 0; i < k; ++i) {
      int nx = (x ^ (1 << i));
      if(dis[nx] > dis[x] + 1) {
	dis[nx] = dis[x] + 1;
	q.push(nx);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < (1 << k); ++i) dis[i] = INF;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < k; ++j) {
      int x; scanf("%1d", &x);
      if(x == 1) a[i] |= (1 << j);
    }
    q.push(a[i]);
    dis[a[i]] = 0;
  }
  bfs();
  int bst = *max_element(dis, dis + (1 << k));
  for(int i = 0; i < (1 << k); ++i) {
    if(dis[i] == bst) {
      for(int j = 0; j < k; ++j) printf("%d", (i >> j) & 1);
      printf("\n");
      return 0;
    }
  }
  return 0;
}
