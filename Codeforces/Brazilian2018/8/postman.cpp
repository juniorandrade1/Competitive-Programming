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

const int N = 2000010;


int n;
vi g[N];
ll s[N], t[N];

void dfs(int x, int ult) {
  s[x] = 1;
  ll add = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
    s[x] += s[y];
    t[x] += t[y];
    t[x] += s[y];
    t[x] += 2 * add * s[y];
    add += s[y];
  }
}

ll ans;

void findRoot(int x, int ult, ll foo) {
  ans = min(ans, foo);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    ll nFoo = foo + (2 * s[y] - n);
    findRoot(y, x, nFoo);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    g[x].pb(y); g[y].pb(x);
  }
  dfs(n - 1, n - 1);
  ans = LINF;
  findRoot(n - 1, n - 1, t[n - 1]);
  printf("%lld\n", ans);
  return 0;
} 