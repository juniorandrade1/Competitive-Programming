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

const int N = 5010;
const int M = 21;

#define EPS 1e-8

struct SparseTable {
  int n;
  int spt[N][M];
  int arr[N];
  int logTable[N];
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
  int in[N], out[N], euler[N], eulerH[N], h[N], counterDfs;
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

LCA *lcaGraph;

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    lcaGraph = new LCA();
    printf("Case %d:\n", i);
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i)  {
      int q; scanf("%d", &q);
      while(q--) {
        int x; scanf("%d", &x);
        lcaGraph->addEdge(i, x);
      }
    }
    lcaGraph->buildLCA();
    int q; scanf("%d", &q);
    while(q--) {
      int a, b; scanf("%d %d", &a, &b);
      printf("%d\n", lcaGraph->getLca(a, b));
    }
  } 
  return 0;
}