#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MAXN = (1 << 19);
const int MAXV = 101;

char tr[MAXN][MAXV];
bitset< MAXN > prop;

void build(int no, int l, int r) {
  for(int i = 0; i < MAXV; ++i) tr[no][i] = i;
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
}

inline void propagate(int no, int l, int r);

void update(int no, int l, int r, int i, int j, char *spt) {
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    prop[no] = 1;
    for(int i = 0; i < MAXV; ++i) tr[no][i] = spt[tr[no][i]];
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  propagate(no, l, r);
  update(nxt, l, mid, i, j, spt); update(nxt + 1, mid + 1, r, i, j, spt);
}

inline void propagate(int no, int l, int r) {
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(prop[no]) {
    update(nxt, l, mid, l, mid, tr[no]);
    update(nxt + 1, mid + 1, r, mid + 1, r, tr[no]);
    for(int i = 0; i < MAXV; ++i) tr[no][i] = i;
    prop[no] = 0;
  }
}

int query(int no, int l, int r, int i, int v) {
  if(l == r) return tr[no][v];
  int nxt = (no << 1), mid = (l + r) >> 1;
  propagate(no, l, r);
  if(i <= mid) return query(nxt, l, mid, i, v);
  else query(nxt + 1, mid + 1, r, i, v);
}


int n;
int v[N];
char need[MAXV];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  build(1, 1, n);
  int q; scanf("%d", &q);
  while(q--) {
    int l, r, x, y; scanf("%d %d %d %d", &l, &r, &x, &y);
    for(int i = 0; i < MAXV; ++i) need[i] = i;
    need[x] = y;
    update(1, 1, n, l, r, need);
  }
  for(int i = 1; i <= n; ++i) {
    if(i != 1) printf(" ");
    printf("%d", query(1, 1, n, i, v[i]));
  }
  return 0;
}