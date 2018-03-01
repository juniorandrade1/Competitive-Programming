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

const int MOD = (ll)1e9 + 7LL;

inline int addMod(int &a, int &b, int md = MOD) {
  a += b;
  if(a >= md) a -= md;
  if(a < 0) a += md;
}

const int N = 300001;

int n, q;
int sum[N];
vector< int > g[N];

inline void init() {
  for(int i = 0; i <= n; ++i) {
    sum[i] = 0;
    g[i].clear();
  }
}

void dfs(int x, int ult, int d, int k, int a, int b) {
  if(d > k) return;
  addMod(sum[x], a);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    int nw = (a + b);
    if(nw >= MOD) nw -= MOD;
    dfs(y, x, d + 1, k, b, nw);
  }
}

inline void main2() {
  scanf("%d %d", &n, &q);
  init();
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  for(int i = 0; i < q; ++i) {
    int op; scanf("%d", &op);
    if(op == 1) {
      int v, k, a, b; scanf("%d %d %d %d", &v, &k, &a, &b);
      dfs(v, v, 0, k, a, b);
    }
    else {
      int v; scanf("%d", &v);
      printf("%d\n", sum[v]);
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}