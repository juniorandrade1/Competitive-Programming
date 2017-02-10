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

const int N = 500010;
const int M = 30;

int n;
ll tr[4 * N], lz[4 * N];
vi g[N];

void propagate(int no, int l, int r) {
  tr[no] += lz[no] * (r - l + 1LL);
  if(l != r) {
    int nxt = (no << 1);
    lz[nxt] += lz[no];
    lz[nxt + 1] += lz[no];
  }
  lz[no] = 0;
}

void build(int no, int l, int r) {
  tr[no] = 0;
  lz[no] = 0;
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid);
  build(nxt + 1, mid + 1, r);
}

void update(int no, int l, int r, int i, int j, ll val) {
  propagate(no, l, r);
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    lz[no] += val;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  update(nxt, l, mid, i, j, val); update(nxt + 1, mid + 1, r, i, j, val);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

ll query(int no, int l, int r, int i, int j) {
  propagate(no, l, r);
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
}

int query(int l, int r) {
  return query(1, 1, n, l, r);
}

void update(int l, int r, ll val) {
  update(1, 1, n, l, r, val);
}


//// seg end

int subSize[N], idChain[N], posInBase[N];
int counterBase = 0;
int lca[N][M], h[N];

void dfs(int x, int ult) {
  subSize[x] = 1;
  lca[x][0] = ult;
  for(int i = 1; i < M; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    h[y] = h[x] + 1;
    dfs(y, x);
    subSize[x] += subSize[y];
  }
}

int getLca(int a, int b) {
  if(h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b];
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) a = lca[a][i];
  if(a == b) return a;
  for(int i = M - 1; i >= 0; --i) if(lca[a][i] != lca[b][i]) a = lca[a][i], b = lca[b][i];
  return lca[a][0];
}

void hld(int x, int chain) {
  idChain[x] = chain;
  posInBase[x] = ++counterBase;
  int idx = -1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(idx == -1 || subSize[idx] < subSize[y]) idx = y;
  }
  if(idx != -1) hld(idx, chain);
  for(int i = 0; i < g[x].size(); ++i) {
    if(g[x][i] == idx) continue;
    hld(g[x][i], g[x][i]);
  }
}

void updateUp(int a, int b, ll val) {
  int chainA = idChain[a], chainB = idChain[b];
  while(chainA != chainB) {
    update(posInBase[chainB], posInBase[b], val);
    b = lca[chainB][0];
    chainB = idChain[b];
  }
  update(posInBase[a], posInBase[b], val);
}

struct queryOrder {
  int r, t, id;
  queryOrder(){};
  queryOrder(int _r, int _t, int _id) {
    r = _r;
    t = _t;
    id = _id;
  }
  bool operator < (queryOrder other) const {
    if(r != other.r) return r < other.r;
    return h[id] < h[other.id];
  }
};

vector< queryOrder > querys;
int root;
ll ans[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int m, r, t;
    scanf("%d %d %d", &m, &r, &t);
    if(m != -1) g[m].pb(i);
    else root = i;
    querys.pb(queryOrder(r, t, i));
  }
  build(1, 1, n);
  dfs(root, root);
  hld(root, root);
  sort(querys.begin(), querys.end());
  for(int i = 0; i < n; ++i) {
    int id = querys[i].id;
    ans[id] = query(1, 1, n, posInBase[id], posInBase[id]);
    updateUp(root, id, querys[i].t);
  }
  for(int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
  return 0;
}