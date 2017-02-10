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

const int N = 100101;
const int M = 18;

int n, m;
set<int> g[N];
int lca[N][M], h[N], subSize[N], par[N];

void dfs0( int x, int ult, int prof )
{
  h[x] = prof;
  lca[x][0] = ult;
  for(set<int>::iterator i=g[x].begin();i!=g[x].end();i++)
  {
    int y = *i;
    if( y == ult ) continue;
    dfs0(y,x,prof+1);
  }
}

int nc;

void dfs1( int x, int ult )
{
  nc++;
  subSize[x] = 1;
  for(set<int>::iterator i=g[x].begin();i!=g[x].end();i++)
  {
    int y = *i;
    if( y == ult ) continue;
    dfs1(y,x);
    subSize[x]+=subSize[y];
  }
}

int dfs2( int x, int ult )
{
  for(set<int>::iterator i=g[x].begin();i!=g[x].end();i++)
  {
    int y = *i;
    if( y == ult ) continue;
    if( subSize[y] > nc/2 ) return dfs2(y,x);
  }
  return x;
}

void process()
{
  for(int j=1;j<M;++j) for(int i=0;i<=n;++i) lca[i][j] = lca[lca[i][j-1]][j-1];
}

int get_lca( int a, int b )
{
  if( h[a] < h[b] ) swap(a,b);
  int d = h[a]-h[b];
  for(int i=M-1;i>=0;--i) if( d&(1<<i) ) a = lca[a][i];
  if( a == b ) return a;
  for(int i=M-1;i>=0;--i) if( lca[a][i] != lca[b][i] ) a = lca[a][i], b = lca[b][i];
  return lca[a][0];
}

int get_dis( int a, int b )
{
  return h[a]+h[b]-2*h[get_lca(a,b)];
}

void preprocess()
{
  dfs0(1,0,0);
  process();
}

void decompose( int x, int ult )
{
  nc = 0;
  dfs1(x,x);
  int centro = dfs2(x,x);
  if( ult == -1 ) par[centro] = centro;
  else par[centro] = ult;
  for(set<int>::iterator  i=g[centro].begin();i!=g[centro].end();i++)
  {
    g[*i].erase(centro);
    decompose(*i,centro);
  }
  g[centro].clear();
}

multiset<int>ans[N];
int op[N];

void update( int x )
{
  int u = x;
  if( !op[x] )
  {
    while(1)
    {
      ans[u].insert(get_dis(u,x));
      if( par[u] == u ) break;
      u = par[u];
    }
  }
  else
  {
    multiset<int>::iterator it;
    while(1)
    {
      it = ans[u].find(get_dis(u,x));
      ans[u].erase(it);
      if( par[u] == u ) break;
      u = par[u];
    }
  }
  op[x]^=1; 
}

int query( int x )
{
  int u = x;
  int ret = INF;
  while(1)
  {
    if( ans[u].begin() != ans[u].end() ) ret = min( ret, *ans[u].begin() + get_dis(x,u) );
    if( par[u] == u ) break;
    u = par[u];
  }
  if( ret == INF ) ret = -1;
  return ret;
}

int main()
{
  //ios::sync_with_stdio(0);
  scanf("%d",&n);
  for(int i=0;i+1<n;++i)
  {
    int a,b; scanf("%d %d",&a,&b);
    g[a].insert(b); g[b].insert(a);
  }
  preprocess();
  decompose(1,-1);

  scanf("%d",&m);
  while(m--)
  {
    int a,b; scanf("%d %d",&a,&b);
    if( a == 0 ) update(b);
    else printf("%d\n",query(b));
  }
  return 0;
}