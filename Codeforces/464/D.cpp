#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100001;

int n;
int g[26][26];
char s[N], t[N];
int vis[26];
vector< pair<int, int > > sol;

void dfs(int x) {
  vis[x] = 1;
  for(int y = 0; y < 26; ++y) {
    if(vis[y]) continue;
    if(g[x][y] == 0) continue;
    sol.push_back(make_pair(x, y));
    dfs(y);
  }
}

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  scanf(" %s", t);
  for(int i = 0; i < n; ++i) {
    int x = s[i] - 'a', y = t[i] - 'a';
    g[x][y] = g[y][x] = 1;
  }
  for(int i = 0; i < 26; ++i) if(vis[i] == 0) dfs(i);
  printf("%d\n", (int)sol.size());
  for(int i = 0; i < (int)sol.size(); ++i) {
    printf("%c %c\n", sol[i].first + 'a', sol[i].second + 'a');
  }
  return 0;
}