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

const int N = 200010;
const int M = 18;
const int B = 300;

int n;
vi g[N];
int b[N];
int f[N];
vi fc;
int dfsCounter = 0;
int in[N], out[N], arr[N];
int lca[N][M], h[N];

void dfs(int x, int ult) {
  arr[dfsCounter] = x;
  in[x] = dfsCounter++;
  lca[x][0] = ult;
  for(int i = 1; i < M; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    h[y] = h[x] + 1;
    dfs(y, x);
  }
  arr[dfsCounter] = x;
  out[x] = dfsCounter++;
}

int getLca(int a, int b) {
  if(h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b];
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) a = lca[a][i];
  if(a == b) return a;
  for(int i = M - 1; i >= 0; --i) if(lca[a][i] != lca[b][i]) {
    a = lca[a][i];
    b = lca[b][i];
  }
  return lca[a][0];
}

struct query {
  int l, r, p, id;
  query(){};
  query(int _l, int _r, int _p, int _id){
    l = _l;
    r = _r;
    p = _p;
    id = _id;
  }
  bool operator < (query other) const {
    if(r / B != other.r / B) return r / B < other.r / B;
    return l < other.l;
  }
};

query allQ[N];
ll sol[N];
ll totSol = 0;

int active[N];
ll cor[2][N];

inline void go(int px) {
  int idx = arr[px];
  totSol -= (cor[0][f[idx]] * cor[1][f[idx]]);
  if(active[idx] == 0) cor[b[idx]][f[idx]]++;
  else cor[b[idx]][f[idx]]--;
  active[idx] ^= 1;
  totSol += (cor[0][f[idx]] * cor[1][f[idx]]);
}

vi compress() {
  vi ret(f + 1, f + n + 1);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", b + i);
  for(int i = 1; i <= n; ++i) scanf("%d", f + i);
  vi cmpf = compress();
  for(int i = 1; i <= n; ++i) f[i] = lower_bound(cmpf.begin(), cmpf.end(), f[i]) - cmpf.begin();
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1, 1);
  int q; scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    int l, r, p = -1;
    if(in[a] > in[b]) swap(a, b);
    p = getLca(a, b);
    if(p == a) {
      l = in[a];
      r = in[b];
      p = -1;
    }
    else {
      l = out[a];
      r = in[b];    
    }  
    allQ[i] = query(l, r, p, i);
  }
  sort(allQ, allQ + q);
  int l = 1, r = 0;
  
  for(int i = 0; i < q; ++i) {
    int ql = allQ[i].l;
    int qr = allQ[i].r;
    while(r < qr) go(++r);
    while(l > ql) go(--l);
    while(r > qr) go(r--);
    while(l < ql) go(l++);
    if(allQ[i].p != -1) go(in[allQ[i].p]);
    sol[allQ[i].id] = totSol; 
    if(allQ[i].p != -1) go(in[allQ[i].p]);
  }
  for(int i = 0; i < q; ++i) printf("%lld\n", sol[i]);
  return 0;
}