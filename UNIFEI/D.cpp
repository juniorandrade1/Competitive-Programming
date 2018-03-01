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

const int N = 1010;

int t, e;
int bs[N];
vi g[N];
bitset<N>emp[N];
int vis[N];

void dfs(int x) {
  if(vis[x]) return;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    emp[y] |= emp[x];
    dfs(y);
  }
}

int calc(int x) {
  int sum = 0;
  for(int i = 1; i <= t; ++i) {
    if(emp[i][x]) sum += bs[i];
  }
  return sum;
}

int main() {
  while(scanf("%d %d", &t, &e) != EOF) {
    if(!t && !e) break;
    for(int i = 1; i <= t; ++i) {
      emp[i].reset();
      g[i].clear();
      int nd, ne;
      scanf("%d %d %d", bs + i, &nd, &ne);
      for(int j = 0; j < nd; ++j) {
        int x; scanf("%d", &x);
        g[i].pb(x);
      }
      for(int j = 0; j < ne; ++j) {
        int x; scanf("%d", &x);
        emp[i][x] = 1;
      }
    }
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= t; ++i) if(!vis[i]) dfs(i);
    puts("*****");
    for(int i = 1; i <= e; ++i) printf("%d %d\n", i, calc(i));
  }
  return 0;
}