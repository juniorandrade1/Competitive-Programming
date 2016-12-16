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

const int N = 2e5 + 10;

int n;
ll a[N];
ll sum[N];
ll maximo[N];
vi all[N];
vi g[N];

void dfs(int x, int ult) {
  sum[x] = a[x];
  maximo[x] = -LINF;
  for(int i = 0; i < all[x].size(); ++i) {
    int y = all[x][i];
    if(y == ult) continue;
    g[x].pb(y);
    dfs(y, x);
    maximo[x] = max(maximo[x], maximo[y]);
    sum[x] += sum[y];
  }
  maximo[x] = max(maximo[x], sum[x]);
}

ll pd[N][3];
short memo[N][3];


ll solve(int pai, int son, int need) {
  if(need == 0) return 0;
  if(son == g[pai].size()) return -LINF;
  int x = g[pai][son];
  if(memo[x][need]) return pd[x][need];
  memo[x][need] = 1;
  ll ret = -LINF;
  for(int i = 0; i <= need; ++i) {
    if(i != 1) ret = max(ret, solve(pai, son + 1, need - i) + solve(x, 0, i));
    else ret = max(ret, solve(pai, son + 1, need - i) + maximo[x]);
  }
  return pd[x][need] = ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 1; i < n; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    all[x].pb(y);
    all[y].pb(x);
  }
  dfs(0, 0);
  ll foo = solve(0, 0, 2);
  if(foo < -4000000000000000) printf("Impossible\n");
  else printf("%lld\n", foo);
  return 0;
}