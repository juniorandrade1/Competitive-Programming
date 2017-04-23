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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 400010;
const int M = 18;

struct querys {
  int op, x, y;
  querys(){};
  querys(int _op, int _x) {
    op = _op;
    x = _x;
    y = -INF;
  }
  querys(int _op, int _x, int _y) {
    op = _op;
    x = _x;
    y = _y;
  }
};


ll tr[4 * N];

void update(int no, int l, int r, int i, int val) {
  if(l == r) {
    tr[no] = val;
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, val);
  else update(nxt + 1, mid + 1, r, i, val);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

ll segQuery(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return segQuery(nxt, l, mid, i, j) + segQuery(nxt + 1, mid + 1, r, i, j);
}


vector< querys > q;
vi g[N];
int in[N], out[N], numChild[N];
int n = 1;
int dfsCounter = 0;
int BUCKET = 0;

vi fatherSQRT[N];
vi atualFather;

int dis[N], lca[N][M];
ll preCalculate[N];

int goUp(int x, int d) {
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) x = lca[x][i];
  return x;
}

void dfs(int x, int ult) {
  fatherSQRT[x] = atualFather;
  if(numChild[x] > BUCKET) atualFather.pb(x);
  in[x] = dfsCounter++;
  lca[x][0] = ult;
  for(int i = 1; i < M; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dis[y] = dis[x] + 1;
    dfs(y, x);
  }
  out[x] = dfsCounter - 1;
  if(numChild[x] > BUCKET) atualFather.pop_back();
}


inline void active(int x, int y) {
  update(1, 0, dfsCounter - 1, in[x], y);
  for(int i = 0; i < fatherSQRT[x].size(); ++i) {
    int p = fatherSQRT[x][i];
    int d = dis[x] - dis[p];
    int jmp = goUp(x, d - 1);
    preCalculate[p] = max(preCalculate[p], segQuery(1, 0, dfsCounter - 1, in[jmp], out[jmp]));
  }
}

inline void query(int x) {
  if(numChild[x] <= BUCKET) {
    ll ans = 0;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      ans = max(ans, segQuery(1, 0, dfsCounter - 1, in[y], out[y]));
    }
    printf("%lld\n", ans);
  }
  else {
    printf("%lld\n", preCalculate[x]);
  }
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 0; i < t; ++i) {
    int op, x, y; scanf("%d", &op);
    if(op == 1) {
      scanf("%d %d", &x, &y);
      n++;
      numChild[x]++;
      g[x].pb(n);
      q.pb(querys(op, n, y));
    }
    else {
      scanf("%d", &x);
      q.pb(querys(op, x));
    }
  }
  BUCKET = sqrt(n);
  dfs(1, 1);
  for(int i = 0; i < t; ++i) {
    if(q[i].op == 1) active(q[i].x, q[i].y);
    else query(q[i].x);
  }
  return 0;
}