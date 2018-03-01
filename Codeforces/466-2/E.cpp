#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int)1e5 + 10;
const int LOGN = 20;
const int MX = (int)1e9;
const ll LINF = (ll)1e17;

template <typename T> 
class SegmentTree {
private:
  vector< T > tr;
  int n;
  void build(int no, int l, int r, vector< T > &v) {
    if(l == r) {
      tr[no] = v[l];
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    build(nxt, l, mid, v); build(nxt + 1, mid + 1, r, v);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
  T query(int no, int l, int r, int i, int j) {
    if(r < i || l > j) return T();
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
  }
  void pointUpdate(int no, int l, int r, int i, T nw) {
    if(l == r) {
      tr[no] = nw;
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    if(i <= mid) pointUpdate(nxt, l, mid, i, nw);
    else pointUpdate(nxt + 1, mid + 1, r, i, nw);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
public:
  SegmentTree(){
    n = 100000;
    tr.resize(n * 4);
  };
  SegmentTree(int _n) {
    n = _n;
    tr.resize(n * 4);
  }
  SegmentTree(vector< T > &v) {
    n = (int)v.size();
    tr.resize(n * 4);
    build(1, 0, n - 1, v);
  }
  T queryRange(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
  void pointUpdate(int i, T nw) {
    pointUpdate(1, 0, n - 1, i, nw);
  }
};

struct NodeMin {
  long long x;
  NodeMin(){
    x = LINF;
  };
  NodeMin(long long _x) {
    x = _x;
  }
  NodeMin operator + (NodeMin other) const {
    return NodeMin(min(x, other.x));
  }
};


int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  vector< NodeMin > v(n, 0);
  ll sum = 0;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    sum += x;
    v[i] = NodeMin(x);
  }
  SegmentTree< NodeMin > minQ(v);
  vector< ll > dp(n + 1, 0);
  for(int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if(i >= c) {
      dp[i] = max(dp[i], dp[i - c] + minQ.queryRange(i - c, i - 1).x);
    }
  }
  printf("%lld\n", sum - dp[n]);
  return 0;
}