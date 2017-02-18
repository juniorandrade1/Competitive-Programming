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

void arquivo() {
  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);
}

const int N = 100010;


struct Segtree {
  int tr[4 * N];
  Segtree(){ memset(tr, 0, sizeof tr); };
  int query(int no, int l, int r, int i, int j) {
    if(r < i || l > j) return 0;
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return max(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
  }
  void update(int no, int l, int r, int i, int val) {
    if(l == r) {
      tr[no] = max(tr[no], val);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    if(i <= mid) update(nxt, l, mid, i, val);
    else update(nxt + 1, mid + 1, r, i, val);
    tr[no] = max(tr[nxt], tr[nxt + 1]); 
  }
};

Segtree seg;
int a[N], b[N];
int ra[N], rb[N];
int n;

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ra[a[i]] = i;
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    rb[b[i]] = i;
  }

  for(int i = 1; i <= n; ++i) {
    int x = a[i];
    vii upd;
    for(int j = max(1, x - 4); j <= min(n, x + 4); ++j) {
      int q = seg.query(1, 1, n + 1, 1, rb[j]);
      upd.pb(mp(rb[j] + 1, q + 1));
    }
    for(int j = 0; j < upd.size(); ++j) seg.update(1, 1, n + 1, upd[j].F, upd[j].S);
  }

  printf("%d\n", seg.query(1, 1, n + 1, 1, n + 1));
  return 0;
}