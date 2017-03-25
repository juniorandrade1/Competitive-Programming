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

const int N = 1000000;

int n, m, k;
int euler[N], sz = 0;
vi g[N];
int vis[N];

void dfs(int x) {
  euler[sz++] = x;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(vis[y]) continue;
    dfs(y);
    euler[sz++] = x;
  }
  //euler[sz++] = x;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(1);
  int maxi = (2 * n + k - 1) / k;
  int p = 0;
  for(int i = 0; i < k; ++i) {
    int tot = min(sz - p, maxi);
    int pp = p + tot;
    if(tot) { 
      printf("%d", tot);
      while(tot--) printf(" %d", euler[p++]);
      p = pp;
    }
    else printf("1 1\n");
    printf("\n");
  }


  return 0;
}