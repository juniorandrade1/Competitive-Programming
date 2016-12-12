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

const int N = 1010;

int n, m, w;
ll a[N], b[N];

int vis[N];
ll peso[N];
ll beleza[N];

vi g[N];
vi group[N];
int cnt = 1;

void dfs(int x, int atGroup) {
  peso[atGroup] += a[x];
  beleza[atGroup] += b[x];
  vis[x] = atGroup;
  group[atGroup].pb(x);
  for(int i = 0; i < g[x].size(); ++i) if(vis[g[x][i]] == 0) dfs(g[x][i], atGroup);
}

ll pd[N][N];

ll func(int pos, int lol) {
  if(pos == cnt) return 0;
  if(pd[pos][lol] != -1) return pd[pos][lol];
  ll ret = func(pos + 1, lol);
  if(lol >= peso[pos]) {
    ret = max(ret, beleza[pos] + func(pos + 1, lol - peso[pos]));
  }
  for(int i = 0; i < group[pos].size(); ++i) {
    int x = group[pos][i];
    if(a[x] <= lol) ret = max(ret, b[x] + func(pos + 1, lol - a[x]));
  }
  return pd[pos][lol] = ret;
}

int main() {
  scanf("%d %d %d", &n, &m, &w);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 0; i < n; ++i) scanf("%lld", b + i);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  for(int i = 0; i < n; ++i) {
    if(vis[i] == 0)  {
      dfs(i, cnt++);
    }
  }

  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(1, w));


  return 0;
}