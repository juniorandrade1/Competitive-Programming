#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 102011;
const int M = 20;

#define EPS 1e-8

struct SparseTable {
  int n;
  int spt[N * 4][M];
  int arr[N * 4];
  int logTable[N * 4];
  SparseTable(int _n, int _arr[]) {
    n = _n;
    for(int i = 0; i < n; ++i) {
      spt[i][0] = i;
      arr[i] = _arr[i];
    }
    logTable[0] = logTable[1] = 0;
    for(int i = 2; i < n; ++i) logTable[i] = logTable[i >> 1] + 1;
    for(int k = 1; (1 << k) < n; ++k) {
      for(int i = 0; i + (1 << k) <= n; i++) {
        int x = spt[i][k - 1];
        int y = spt[i + (1 << k - 1)][k - 1];
        if(arr[x] < arr[y]) spt[i][k] = x;
        else spt[i][k] = y;
      }
    }
  }
  int getMaxIdx(int l, int r) {
    int k = logTable[r - l];
    int x = spt[l][k];
    int y = spt[r - (1 << k) + 1][k];
    if(arr[x] < arr[y]) return x;
    else return y;
  }
};

struct LCA {
  vi g[N];
  int in[N], out[N], euler[N * 4], eulerH[N * 4], h[N], counterDfs;
  SparseTable *spt;
  LCA(){ counterDfs = 0; };
  void dfs(int x, int ult, int height) {
    in[x] = counterDfs;
    euler[counterDfs++] = x;
    h[x] = height;
    int count = 0;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      if(y == ult) continue;
      count++;
      dfs(y, x, height + 1);
      out[x] = counterDfs;
      euler[counterDfs++] = x;
    }
    if(count == 0) {
      out[x] = counterDfs;
      euler[counterDfs++] = x;
    }
  }
  void addEdge(int x, int y) {
    g[x].pb(y);
    g[y].pb(x);
  }
  void buildLCA() {
    dfs(1, 0, 0);
    for(int i = 0; i < counterDfs; ++i) eulerH[i] = h[euler[i]];
    spt = new SparseTable(counterDfs, eulerH);
  }
  int getLca(int x, int y) {
    return euler[spt->getMaxIdx(min(in[x], in[y]), max(in[x], in[y]))];
  }
};

LCA lcaGraph;
ll bit[N];

void addBit(int x, ll z) {
  x += 2;
  while(x < N) {
    bit[x] += z;
    x += LSONE(x);
  }
}

ll queryBit(int x) {
  x += 2;
  ll ret = 0;
  while(x) {
    ret += bit[x];
    x -= LSONE(x);
  }
  return ret;
}

vii g[N];
int lca[N];
int n;
int in[N], out[N], h[N];
int dfsCounter = 1;

void dfs(int x, int ult, ll carry) {
  in[x] = dfsCounter++;
  lca[x] = ult;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].F, w = g[x][i].S;
    if(y == ult) continue;
    h[y] = h[x] + 1;
    dfs(y, x, w);
  }
  out[x] = dfsCounter;
  addBit(in[x], carry);
  addBit(out[x], -carry);
}

ll getDistance(int x, int y) {
  ll dx = queryBit(in[x]);
  ll dy = queryBit(in[y]);
  ll dl = queryBit(in[lcaGraph.getLca(x, y)]);
  return dx + dy - 2 * dl;
}

map< ii, int > myMap;
void updateEdge(int u, int v, ll w) {
  ll antigo = myMap[ii(u, v)];
  ll delta = w - antigo;
  if(lca[u] == v) {
    addBit(in[u], delta);
    addBit(out[u], -delta);
  }
  else {
    addBit(in[v], delta);
    addBit(out[v], -delta);
  }
  myMap[ii(u, v)] = w;
}

pair< ii, ii > maxDist[N];
vi allSpecial;

void processQuery() {
  allSpecial.clear();
  int k; scanf("%d", &k);
  for(int i = 0; i < k; ++i) {
    int x; scanf("%d", &x);
    allSpecial.pb(x);
  }
  ll d = 0, id = allSpecial[0];
  for(int i = 1; i < k; ++i) {
    ll w = getDistance(id, allSpecial[i]);
    if(w > d) {
      d = w;
      id = allSpecial[i];
    }
  }
  ll idA, dA = -1;
  for(int i = 0; i < k; ++i) {
    ll w = getDistance(id, allSpecial[i]);
    if(w > dA) {
      dA = w;
      idA = allSpecial[i];
    }
  }
  ll idB, dB = -1;
  for(int i = 0; i < k; ++i) {
    ll w = getDistance(idA, allSpecial[i]);
    if(w > dB) {
      dB = w;
      idB = allSpecial[i];
    }
  }  
  for(int i = 0; i < k; ++i) {
    if(i) printf(" ");
    printf("%lld", max(getDistance(allSpecial[i], idA), getDistance(allSpecial[i], idB)));
  }
  printf("\n"); 
}

inline void init() { for(int i = 0; i <= n; ++i) maxDist[i] = make_pair(ii(-1, -1), ii(-1, -1)); }

int main() {
  scanf("%d", &n);
  init();
  for(int i = 0; i + 1 < n; ++i) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    g[u].pb(mp(v, w));
    g[v].pb(mp(u, w));
    myMap[ii(min(u, v), max(u, v))] = w;
    lcaGraph.addEdge(u, v);
  }
  dfs(1, 0, 0);
  lcaGraph.buildLCA();
  int q; scanf("%d", &q);
  while(q--) {
    int op; scanf("%d", &op);
    if(op == 1) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      updateEdge(min(u, v), max(u, v), w);
    }
    else processQuery();
  }
  return 0;
}