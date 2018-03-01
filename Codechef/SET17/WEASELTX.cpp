#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< int, int > ii;
typedef vector< int > vi;
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

const int N = 200000;
const int M = 70;

int n, m;
vi g[N];
ll v[N][M];

void dfs(int x, int ult, int lvl) {
  v[x][lvl] = v[x][lvl - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x, lvl);
    v[x][lvl] ^= v[y][lvl - 1];
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i + 1 < n; ++i){
    int x, y; scanf("%d %d", &x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  for(int i = 0; i < n; ++i) scanf("%lld", &v[i][0]);
  for(int i = 1; i < M; ++i) dfs(0, 0, i);
  int cycle = 1;
  for(int i = 1; i < M; ++i) if(v[0][0] == v[0][i]) {
    cycle = i;
    break;
  }
  while(m--) {
    ll x; scanf("%lld", &x);
    printf("%lld\n", v[0][x % cycle]);
  }
  return 0;
}