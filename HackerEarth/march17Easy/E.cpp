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

const int N = 100010;
const int MOD = 1e9 + 7LL;

ll dad[N];
ll pd[N][21];
short memo[N][21];
int test = 1;
int n, m;
vi g[N];
int isLeave[N], myDad[N];
ll gcdTable[21][21];

inline ll addMod(ll a, ll b, ll md = MOD) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

void dfs(int x, int ult) {
  isLeave[x] = 1;
  myDad[x] = ult;

  int idxDad = -1;
  for(int i = 0; i < g[x].size(); ++i) {
    if(g[x][i] == ult) {
      idxDad = i;
      continue;
    }
    isLeave[x] = 0;
    dfs(g[x][i], x);
  }

  if(idxDad != -1) g[x].erase(g[x].begin() + idxDad);
}

ll func(int pai, int id, int gcd) {
  int y = g[pai][id];
  if(isLeave[pai]) return gcd == 1;
  if(g[pai].size() == id) return 0;
  if(memo[y][gcd] == test) return pd[y][gcd];
  ll ret = 0;
  for(int i = 1; i <= m; ++i) {
    if(id + 1 < g[pai].size()) ret = addMod(ret, mulMod(func(y, 0, gcdTable[i][gcd]), func(pai, id + 1, gcd)));
    else ret = addMod(ret, func(y, 0, gcdTable[i][gcd]));
  }
  memo[y][gcd] = test;
  return pd[y][gcd] = ret;
}

inline void main2() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i <= n; ++i) g[i].clear();
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(1, 0);
  ll ans = 0;
  for(int i = 1; i <= m; ++i) ans = addMod(ans, func(1, 0, i));
  printf("%lld\n", ans);
}

int main() {
  for(int i = 1; i <= 20; ++i) for(int j = 1; j <= 20; ++j) gcdTable[i][j] = __gcd(i, j);
  main2();
  return 0;
}