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

#define pi acos(-1.0)
#define eps 1e-6

const int N = 1e5 + 10;

struct est {
  int l, r, x, h;
  est(){};
  est(int _l, int _r, int _x, int _h) {
    l = _l;
    r = _r;
    x = _x;
    h = _h;
  }
  bool operator < (est other) const {
    if(h != other.h) return h < other.h;
    return l < other.l;
  }
};

struct Segtree {
  vi tr, lz;
  int n;
  Segtree(){};
  Segtree(int _n) {
    n = _n;
    tr = vi(n * 4, 0);
    lz = vi(n * 4, 0);
  }
  void propagate(int no, int l, int r) {
    tr[no] += lz[no];
    if(l != r) {
      int nxt = (no << 1);
      lz[nxt] += lz[no];
      lz[nxt + 1] += lz[no];
    }
    lz[no] = 0;
  }
  void update(int no, int l, int r, int i, int j, int val) {
    propagate(no, l, r);
    if(r < i || l > j) return;
    if(l >= i && r <= j) {
      lz[no] += val;
      propagate(no, l, r);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    update(nxt, l, mid, i, j, val);
    update(nxt + 1, mid + 1, r, i, j, val);
    tr[no] = min(tr[nxt], tr[nxt + 1]);
  }
  int query(int no, int l, int r, int i, int j) {
    if(r < i || l > j) return 0;
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return min(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
  }
};

const int TOT = 500000;
const int HALF = TOT / 2;

int n;
vector< est > up;
Segtree *upSeg;
vii ans;

inline void process() {
  upSeg = new Segtree(TOT);
  sort(up.begin(), up.end());
  
  for(int i = 0; i < up.size(); ++i) {
    int sol = upSeg->query(1, 0, TOT - 1, up[i].l, up[i].r);
    if(sol) ans.pb(mp(up[i].x, up[i].h));
    upSeg->update(1, 0, TOT - 1, up[i].l, up[i].r, 1);
  }
  sort(ans.begin(), ans.end());
}

inline void main2() {
  up.clear();
  ans.clear();
  for(int i = 0; i < n; ++i) {
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    up.pb(est(x - z + HALF, x + z + HALF, x, y));
  }
  process();
  if(ans.size() == 0) printf("All the lights are visible.\n");
  else {
    puts("Some lights are not visible:");
    for(int i = 0; i < ans.size(); ++i) {
      printf("x = %lld, y = %lld", ans[i].F, ans[i].S);
      if(i + 1 == ans.size()) printf(";\n");
      else printf(":\n");
    }
  }
}

int main() {
  while(1) {
    scanf("%d", &n);
    if(!n) break;
    main2();
  }

  return 0;
}