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

const int N = 500000;

int n, q;
vii g[N];
int vis[N];

int dfs(int x) {
  bool ok = true;
  for(int i = 0; i < g[x].size() && ok; ++i) {
    int y = g[x][i].F, w = g[x][i].S;
    if(vis[y] == -1) {
      vis[y] = (vis[x] + w) % 2;
      dfs(y);
    }
    else if((vis[x] + w) % 2 != vis[y]) ok = false;
  }
  return ok;
}

inline void main2() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i <= n; ++i) {
    g[i].clear();
    vis[i] = -1;
  }
  while(q--) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }
  for(int i = 0; i < n; ++i) {
    if(vis[i] == -1) {
      vis[i] = 0;
      if(dfs(i) == false)  {
        puts("no");
        return;
      }
    }
  }
  puts("yes");  
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}