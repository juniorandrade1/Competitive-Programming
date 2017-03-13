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

const int N = 220000;

int n, m;
vi g[N];

void addEdge(int x, int y) {
  g[x].pb(y + n + 1);
  //g[y].pb(x + n + 1);
}

int vis[N], match[N];

int dfs(int x) {
  if(vis[x]) return 0;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(match[y] == -1 || dfs(match[y])) {
      match[y] = x;
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    addEdge(a, b);
  }
  int ans = 0;
  memset(match, -1, sizeof match);
  for(int i = 0; i < n; ++i) {
    memset(vis, 0, sizeof vis);
    ans += dfs(i);
  }
  puts(ans == n ? "YES" : "NO");
  return 0;
}