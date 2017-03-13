#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1010;

struct Segtree {
  ii tr[4 * N];
  ii join(ii a, ii b) {
    return ii(min(a.F, b.F), max(a.S, b.S));
  }
  Segtree(){};
  void update(int no, int l, int r, int i, int val) {
    if(l == r) {
      tr[no] = ii(val, val);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    if(i <= mid) update(nxt, l, mid, i, val);
    else update(nxt + 1, mid + 1, r, i, val);
    tr[no] = join(tr[nxt], tr[nxt + 1]);
  }
  ii query(int no, int l, int r, int i, int j) {
    if(r < i || l > j) return ii(INF, -INF);
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
  }
  bool same(int no, int l, int r, int i, int j) {
    ii a = query(no, l, r, i, j);
    return a.F - a.S == 0;
  }
};

int n;
int v[N][N];
int dir[N][N], down[N][N];
Segtree sDir[N], sDown[N];

bool test(int x) {
  for(int i = 1; i + x - 1 <= n; ++i) {
    for(int j = 1; j + x - 1 <= n; ++j) {
      int ni = i + x - 1;
      int nj = j + x - 1;
      if(sDown[i].same(1, 1, n, j, nj) && sDir[j].same(1, 1, n, i, ni)) return true;
    }
  }
  return false;
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &v[i][j]);    
  for(int i = n; i >= 1; --i) for(int j = n; j >= 1; --j) {
    if(j == n) dir[i][j] = 1;
    else if(v[i][j] == v[i][j + 1]) dir[i][j] = dir[i][j + 1] + 1;
    else dir[i][j] = 1;
    sDir[j].update(1, 1, n, i, v[i][j]);

    if(i == n) down[i][j] = 1;
    else if(v[i][j] == v[i + 1][j]) down[i][j] = down[i + 1][j] + 1;
    else down[i][j] = 1;
    sDown[i].update(1, 1, n, j, v[i][j]);
  }

  int lo = 0, hi = n;

  while(lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if(test(mid)) lo = mid;
    else hi = mid - 1;
  }
  
  printf("%d\n", lo);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}