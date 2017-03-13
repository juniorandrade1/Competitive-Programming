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

const int N = 200010;

int n;
vi g[N];
int cor[N];
int dfsCount = 0;
int sz[N], in[N], ot[N], vt[N];

void dfs0(int x, int p) {
  in[x] = dfsCount;
  vt[dfsCount++] = x;
  sz[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == p) continue;
    dfs0(y, x);
    sz[x] += sz[y];
  }
  ot[x] = dfsCount;
}

ll ans[N];
ll cntColor[N];

multiset<int>allQtd;
ll sumQtd[N];

void add(int cc, int op) {
  if(op == 1) {
    if(cntColor[cc]) {
      sumQtd[cntColor[cc]] -= (cc + 1);
      allQtd.erase(allQtd.find(cntColor[cc]));
    }
    cntColor[cc]++;
    sumQtd[cntColor[cc]] += (cc + 1);
    allQtd.insert(cntColor[cc]);
  }
  else {
    sumQtd[cntColor[cc]] -= (cc + 1);
    allQtd.erase(allQtd.find(cntColor[cc]));
    cntColor[cc]--;
    if(cntColor[cc]) {
      sumQtd[cntColor[cc]] += (cc + 1);
      allQtd.insert(cntColor[cc]);
    }
  }
}


void solve(int x, int p, bool keep) {
  int bigChild = -1;
  int mx = -1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == p) continue;
    if(sz[y] > mx) {
      mx = sz[y];
      bigChild = y;
    }
  }
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == p || y == bigChild) continue;
    solve(y, x, 0);
  }

  if(bigChild != -1) solve(bigChild, x, 1);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == p || y == bigChild) continue;
    for(int j = in[y]; j < ot[y]; ++j) add(cor[vt[j]], 1);
  }
  add(cor[x], 1);
  multiset<int>::iterator it = allQtd.end();
  it--;
  ans[x] = sumQtd[*it];
  if(!keep) for(int i = in[x]; i < ot[x]; ++i) add(cor[vt[i]], -1);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", cor + i), cor[i]--;
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs0(0, 0);
  solve(0, 0, 0);
  for(int i = 0; i < n; ++i) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}