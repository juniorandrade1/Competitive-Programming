#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

const int N = 1000000;

int n, m;
int vis[N];
vi g[N];

void addEdge(int x, int y) {
  g[x].pb(y);
  g[y ^ 1].pb(x ^ 1);
}

int cycle = 0;

void dfs(int x, int ult) {
  if(vis[x]) {
    if(vis[x] == 1) cycle = 1;
    return;
  }
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
  }
  vis[x] = 2;
}

int main() {
  scanf("%d %d", &n, &m);
  n *= 2;
  for(int i = 0; i < m; ++i) {
    char oa, ob;
    int a, b;
    scanf(" %c %d %c %d", &oa, &a, &ob, &b); a--; b--;
    a *= 2; b *= 2;
    if(oa == '-') a ^= 1;
    if(ob == '-') b ^= 1;
    addEdge(a ^ 1, b);
  }
  for(int i = 0; i < n && !cycle; ++i) {
    if(vis[i]) continue;
    dfs(i, -1);
  }
  puts(!cycle ? "TAK" : "NIE");
  return 0;
}