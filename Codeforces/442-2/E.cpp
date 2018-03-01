#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

struct SegmentTree {
  vector< int > tr;
  vector< int > lz;
  int n;
  SegmentTree(){};
  SegmentTree(int _n) {
    n = _n + 1;
    tr.resize(4 * n);
    lz.resize(4 * n);
  }
  void propagate(int no, int l, int r) {
    if(lz[no] == 1) tr[no] = (r - l + 1) - tr[no];
    if(l != r) {
      int nxt = (no << 1);
      lz[nxt] ^= lz[no];
      lz[nxt + 1] ^= lz[no];
    }
    lz[no] = 0;
  }
  void update(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return;
    if(l >= i && r <= j) {
      lz[no] ^= 1;
      propagate(no, l, r);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    update(nxt, l, mid, i, j); update(nxt + 1, mid + 1, r, i, j);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
  int query(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return 0;
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
  }
  void update(int l, int r) {
    update(1, 0, n, l, r);
  }
  int query(int l, int r) {
    return query(1, 0, n, l, r);
  }
};

int L[N], R[N], dfsCounter = 0;

void dfs(int x, int ult, vector< vector< int > > &g) {
  L[x] = dfsCounter;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfsCounter++;
    dfs(y, x, g);
  }
  R[x] = dfsCounter;
}

int main() {
  int n;
  scanf("%d", &n);
  vector< vector< int > > g(n + 1);
  for(int i = 2; i <= n; ++i) {
    int p; scanf("%d", &p);
    g[p].push_back(i);
  }
  dfs(1, 1, g);
  SegmentTree seg(n);
  for(int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    if(x) {
      seg.update(L[i], L[i]);
    }
  }
  int q; scanf("%d", &q);
  while(q--) {
    char str[12]; int x;
    scanf(" %s %d", str, &x);
    if(str[0] == 'g') printf("%d\n", seg.query(L[x], R[x]));
    else seg.update(L[x], R[x]);
  }
  return 0;
}