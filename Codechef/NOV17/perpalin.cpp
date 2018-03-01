#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m;
int vis[N];
int component;

void dfs(int x) {
  if(x >= n) return;
  if(vis[x]) return;
  vis[x] = component;
  dfs(x + m);
  dfs(n - x - 1);
}

inline void main2() {
  scanf("%d %d", &n, &m);
  if(m == 1) {
    puts("impossible");
    return;
  }
  if(n == m) {
    if(n == 2) puts("impossible");
    else {
      printf("a");
      for(int i = 0; i + 2 < n; ++i) printf("b");
      printf("a\n");
    }
    return;
  }
  for(int i = 0; i < n; ++i) vis[i] = 0;
  component = 0;
  for(int i = 0; i < n; ++i) {
    if(vis[i] == 0) {
      component++;
      dfs(i);
    }
  }
  if(component == 1) puts("impossible");
  else {
    for(int i = 0; i < n; ++i) if(vis[i] != vis[n - i - 1]) {
      puts("impossible");
      return;
    }
    for(int i = 0; i < n; ++i) printf("%c", (vis[i] % 2) + 'a');
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}