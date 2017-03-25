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
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 400010;

int n;
int X[N], Y[N];
int tr[4 * N], lz[4 * N];

inline int join(int a, int b) {
  return min(a, b);
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
  update(nxt, l, mid, i, j, val); update(nxt + 1, mid + 1, r, i, j, val);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
}

int query(int no, int l, int r, int i, int j) {
  propagate(no, l, r);
  if(r < i || l > j) return INF;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

void build(int no, int l, int r) {
  lz[no] = tr[no] = 0;
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
}

set<int>sx, sy;
unordered_map<int, int>rx, ry;
vector< ii > g[N][2];

struct rectangle {
  int xi, yi, xf, yf;
  rectangle(){};
  rectangle(int _xi, int _yi, int _xf, int _yf) {
    xi = _xi;
    yi = _yi;
    xf = _xf;
    yf = _yf;
  }
  bool overlap(rectangle other) {
    if(xi >= other.xi && xi <= other.xf && yi >= other.yi && yi <= other.yf) return true;
    if(xf >= other.xi && xf <= other.xf && yf >= other.yi && yf <= other.yf) return true;
    if(xi >= other.xi && xi <= other.xf && yf >= other.yi && yf <= other.yf) return true;
    if(xf >= other.xi && xf <= other.xf && yi >= other.yi && yi <= other.yf) return true;
    return false;
  }
};

inline bool inside(int x, int y, int rng) {
  rectangle a = rectangle(-rng, -rng, rng, rng);
  rectangle b = rectangle(x - rng, y - rng, x + rng, y + rng);
  int xl = max(a.xi, b.xi);
  int yl = max(a.yi, b.yi);
  int xr = min(a.xf, b.xf);
  int yr = min(a.yf, b.yf);
  return (xl <= xr && yl <= yr);
}

inline bool ok(int rng) {
  sx.clear();
  sy.clear();
  rx.clear();
  ry.clear();

  for(int i = 0; i < n; ++i) {
    //if(inside(X[i], Y[i], rng)) {
      sx.insert(X[i] - rng);
      sx.insert(X[i] + rng);
      sy.insert(Y[i] + rng);
      sy.insert(Y[i] - rng);
    //}
  }

  sx.insert(rng);
  sx.insert(-rng);

  sy.insert(rng);
  sy.insert(-rng);

  int cx = 1, cy = 1;
  for(set<int>::iterator it = sx.begin(); it != sx.end(); it++) rx[*it] = cx++;
  for(set<int>::iterator it = sy.begin(); it != sy.end(); it++) ry[*it] = cy++;


  build(1, 0, cy);
  for(int i = 0; i < cx; ++i) g[i][0].clear(), g[i][1].clear();

  for(int i = 0; i < n; ++i) {
    int xl = rx[X[i] - rng], xr = rx[X[i] + rng];
    int yl = ry[Y[i] - rng], yr = ry[Y[i] + rng];
    g[xl][0].pb(mp(yl, yr));
    g[xr][1].pb(mp(yl, yr));
  }

  int xOn = rx[-rng], xOff = rx[rng];
  int lOn = ry[-rng], rOn = ry[rng];

  int ok = 0;
  for(int i = 0; i < cx; ++i) {
    if(i == xOn) ok = 1;
    for(int j = 0; j < g[i][0].size(); ++j) update(1, 0, cy, g[i][0][j].F, g[i][0][j].S, 1);
    if(ok && query(1, 0, cy, lOn, rOn) == 0) return true;
    for(int j = 0; j < g[i][1].size(); ++j) update(1, 0, cy, g[i][1][j].F, g[i][1][j].S, -1);
    if(i == xOff) break;
  }
  return false;
}

int main() {
  int testNumber = 1;
  while(1) {
    scanf("%d", &n);
    if(n == -1) break;
    for(int i = 0; i < n; ++i) scanf("%d %d", X + i, Y + i);
    int lo = 0, hi = 1000000000;
    while(lo < hi) {
      int mid = (lo + hi) >> 1;
      if(ok(mid)) lo = mid + 1;
      else hi = mid;
    }
    if(ok(lo)) printf("Case %d: never\n", testNumber++);
    else printf("Case %d: %d\n", testNumber++, lo);
  }
  return 0;
}