#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

struct Node {
  ll val, min_val, max_val;
  Node(){};
  Node(ll _val, ll _min_val, ll _max_val) {
    val = _val;
    max_val = _max_val;
    min_val = _min_val;
  }
  Node operator + (Node other) const {
    return Node(val + other.val, min(min_val, other.min_val), max(max_val, other.max_val));
  }
};

Node tr[4 * N];
ll lz[4 * N];
int n, m;

void build(int no, int l, int r, vector< ll > &v) {
  lz[no] = -1;
  if(l == r) {
    tr[no] = Node(v[l], v[l], v[l]);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid, v); build(nxt + 1, mid + 1, r, v);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

inline void propagate(int no, int l, int r) {
  if(lz[no] == -1) return;
  tr[no] = Node((r - l + 1LL) * lz[no], lz[no], lz[no]);
  if(l != r) {
    int nxt = (no << 1);
    lz[nxt] = lz[no];
    lz[nxt + 1] = lz[no];
  }
  lz[no] = -1;
}

ll query(int no, int l, int r, int i, int j) {
  propagate(no, l, r);
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no].val;
  int nxt = (no << 1), mid = (l + r) >> 1;
  return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
}

void updateSet(int no, int l, int r, int i, int j, ll x) {
  propagate(no, l, r);
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    lz[no] = x;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  updateSet(nxt, l, mid, i, j, x); updateSet(nxt + 1, mid + 1, r, i, j, x);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

void updateMod(int no, int l, int r, int i, int j, int x) {
  propagate(no, l, r);
  if(r < i || l > j || tr[no].max_val < x) return;
  if(l >= i && r <= j && tr[no].min_val == tr[no].max_val) {
    int v = tr[no].max_val % x;
    lz[no] = v;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  updateMod(nxt, l, mid, i, j, x); updateMod(nxt + 1, mid + 1, r, i, j, x);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

int main() {
  scanf("%d %d", &n, &m);
  vector< ll > a(n);
  for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  build(1, 0, n - 1, a);
  for(int i = 0; i < m; ++i) {
    int op; scanf("%d", &op);
    if(op == 1) {
      int l, r; scanf("%d %d", &l, &r); l--; r--;
      printf("%lld\n", query(1, 0, n - 1, l, r));
    }
    else if(op == 2) {
      int l, r, x; scanf("%d %d %d", &l, &r, &x); l--; r--;
      updateMod(1, 0, n - 1, l, r, x);
    }
    else {
      int k, x; scanf("%d %d", &k, &x); k--;
      updateSet(1, 0, n - 1, k, k, x);
    }
  }
  return 0;
}