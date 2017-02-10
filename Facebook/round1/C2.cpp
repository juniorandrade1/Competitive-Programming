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

const int N = 101;
const int M = 5003;

int n, m, q;
ll g[N][N];
ll pd[M][3][2];
int st[M], ed[M];

ll func(int p1, int p2, int op) {
  if(p1 == q) return 0;
  if(pd[p1][p2][op] != -1) return pd[p1][p2][op];
  int x = 0;
  ll ret = LINF;
  if(op == 0) x = st[p1 + p2 - 1];
  else x = ed[p1];
  if(p1 + p2 < q && p2 < 2) ret = min(ret, func(p1, p2 + 1, 0) + g[x][st[p1 + p2]]);
  if(p2) ret = min(ret, func(p1 + 1, p2 - 1, 1) + g[x][ed[p1]]);
  return pd[p1][p2][op] = ret;
}

inline void main2() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(i != j) g[i][j] = LINF; else g[i][j] = 0;
  for(int i = 0; i < m; ++i) {
    ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c); a--; b--;
    g[a][b] = min(g[a][b], c);
    g[b][a] = min(g[b][a], c);
  }
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  st[0] = ed[0] = 0;
  for(int i = 1; i <= q; ++i) scanf("%d %d", st + i, ed + i), st[i]--, ed[i]--;
  q++;
  for(int i = 0; i <= q; ++i) for(int j = 0; j <= 3; ++j) pd[i][j][0] = pd[i][j][1] = -1;
  ll ans = func(1, 0, 0);
  if(ans >= LINF) ans = -1;
  printf(" %lld\n", ans);
}

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}