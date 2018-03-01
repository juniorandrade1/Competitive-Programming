#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300001;
const int SN = 1000001;

int d[SN];

void pre() {
  for(int i = 1; i < SN; ++i) for(int j = 1; j * i < SN; ++j) d[j * i]++;
}

struct Node {
  ll s, m;
  Node(){};
  Node(ll _s, ll _m) {
    s = _s;
    m = _m;
  }
  Node operator + (Node other) const {
    return Node(s + other.s, max(m, other.m));
  }
};

int n;
ll v[N];
Node tr[4 * N];

void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = Node(v[l], v[l]);
    return;
  }
  int nxt = (no << 1), md = (l + r) >> 1;
  build(nxt, l, md); build(nxt + 1, md + 1, r);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

void update(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return;
  if(tr[no].m <= 2) return;
  if(l == r) {
    tr[no] = Node(d[tr[no].s], d[tr[no].s]);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  update(nxt, l, mid, i, j);
  update(nxt + 1, mid + 1, r, i, j);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

ll query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no].s;
  int nxt = (no << 1), mid = (l + r) >> 1;
  return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
}

int main() {
  pre();
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  build(1, 0, n - 1);
  for(int i = 0; i < m; ++i) {
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    if(op == 1) update(1, 0, n - 1, l - 1, r - 1);
    else printf("%lld\n", query(1, 0, n - 1, l - 1, r - 1));    
  }
  return 0;
}