#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int M = 100010;

struct No {
  int op, x, y, id;
  No(int _op, int _x, int _y, int _id) {
    op = _op;
    x = _x;
    y = _y;
    id = _id;
  }
};

int n, m, q;
int book[N][N];
int invert[N];
int countX[N];
int ans = 0;
vector< No > g[N];


int sol[M];

void dfs(int u) {
  sol[u] = ans;
  for(int i = 0; i < g[u].size(); ++i) {  
    int t = g[u][i].op, x = g[u][i].x, y = g[u][i].y, id = g[u][i].id;
    int ok = 0;
    if(t == 1) {
      int op = (invert[x] ^ book[x][y]);
      if(op == 0) {
        ans++;
        countX[x]++;
        book[x][y] ^= 1;
        ok = 1;
      }
    }
    else if(t == 2) {
      int op = (invert[x] ^ book[x][y]);
      if(op == 1) {
        ans--;
        countX[x]--;
        book[x][y] ^= 1;
        ok = 1;
      }
    }
    else {
      ans -= countX[x];
      invert[x] ^= 1;
      countX[x] = (m - countX[x]);
      ans += countX[x];
      ok = 1;
    }
    dfs(id);
    if(ok) {
      if(t == 1) {
        ans--;
        countX[x]--;
        book[x][y] ^= 1;
      }
      else if(t == 2) {
        ans++;
        countX[x]++;
        book[x][y] ^= 1;
      }
      else {
        ans -= countX[x];
        invert[x] ^= 1;
        countX[x] = (m - countX[x]);
        ans += countX[x];
      } 
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < q; ++i) {
    int op, x, y;
    scanf("%d %d", &op, &x);
    if(op <= 2) scanf("%d", &y);
    if(op == 1) {
      g[i].push_back(No(op, x, y, i + 1));
    } 
    if(op == 2) {
      g[i].push_back(No(op, x, y, i + 1));
    }
    if(op == 3) {
      g[i].push_back(No(op, x, -1, i + 1));
    }
    if(op == 4) {
      g[x].push_back(No(op, -1, -1, i + 1));
    }
  }
  dfs(0);
  for(int i = 0; i < q; ++i) {
    printf("%d\n", sol[i]);
  }
  return 0;
}