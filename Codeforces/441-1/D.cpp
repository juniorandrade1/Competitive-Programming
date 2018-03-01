#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

struct Node {
  long long mx, xr;
  Node() {
    mx = xr = 0;
  }
  Node(long long _mx, long long _xr) {
    mx = _mx;
    xr = _xr;
  }
  Node operator + (Node other) {
    return Node(max(mx, other.mx), xr | other.xr);
  }
};

struct SegTree {
  Node tr[4 * N];
  int n;
  SegTree(){};
  void update(int no, int l, int r, int i, Node v) {
    if(l == r) {
      tr[no] = v;
      return;
    }
    int nxt = (no << 1), md = (l + r) >> 1;
    if(i <= md) update(nxt, l, md, i, v);
    else update(nxt + 1, md + 1, r, i, v);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
  Node query(int no, int l, int r, int i, int j) {
    if(r < i || l > j) return Node();
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), md = (l + r) >> 1;
    return query(nxt, l, md, i, j) + query(nxt + 1, md + 1, r, i, j);
  }
};

int n;
int v[N];
int leftGreater[N], rightGreater[N];
int leftOr[N], rightOr[N];
SegTree seg;

inline void precalculate() {
  stack< pair<int, int> > st;

  while(!st.empty()) st.pop();
  st.push(make_pair(2000000000, 0));
  for(int i = 1; i <= n; ++i) {
    while(!st.empty() && st.top().first > v[i]) st.pop();
    leftGreater[i] = st.top().second;
    st.push(make_pair(v[i], i));
  }

  while(!st.empty()) st.pop();
  st.push(make_pair(2000000000, n + 1));
  for(int i = n; i >= 1; --i) {
    while(!st.empty() && st.top().first > v[i]) st.pop();
    rightGreater[i] = st.top().second;
    st.push(make_pair(v[i], i));
  }

  leftOr[1] = 1;
  for(int i = 2; i <= n; ++i) {
    leftOr[i] = leftOr[i - 1];
    while(seg.query(1, 1, n, leftOr[i], i).xr > v[i]) leftOr[i]++;
  }

  rightOr[n] = n;
  for(int i = n - 1; i >= 1; --i) {
    rightOr[i] = rightOr[i + 1];
    while(seg.query(1, 1, n, i, rightOr[i]).xr > v[i]) rightOr[i]--;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i), seg.update(1, 1, n, i, Node(v[i], v[i]));
  precalculate();
  long long sol = 0;
  for(int i = 1; i <= n; ++i) {

  }
  printf("%lld\n", sol);
  return 0;
}