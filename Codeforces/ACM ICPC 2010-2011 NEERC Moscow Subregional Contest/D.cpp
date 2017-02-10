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
#define pi acos(-1.0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 100110;

int marc[N];
int n, k, l;
vii g[N];
ii dis[N];

inline void dij() {
  pq< ii > q;
  for(int i = 0; i <= n; ++i) {
    dis[i] = ii(LINF, LINF);
    if(marc[i]) {
      dis[i] = ii(0, i);
      q.push(mp(0, i));
    }
  }
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    ll x = foo.S, w = -foo.F;
    if(dis[x].F != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll cost = g[x][i].S;
      if(dis[y].F > dis[x].F + cost) {
        dis[y] = ii(dis[x].F + cost, dis[x].S);
        q.push(mp(-dis[y].F, y));
      }
    }
  }
  ll minDist = LINF;
  for(int x = 0; x < n; ++x) {
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll w = g[x][i].S;
      if(dis[x].S != dis[y].S) minDist = min(minDist, (dis[x].F + dis[y].F + w));
    }
  }
  printf("%lld\n", minDist * 3LL);
}

int main() {
  scanf("%d %d %d", &k, &n, &l);
  for(int i = 0; i < k; ++i){
    int x; scanf("%d", &x); x--;
    marc[x]++;
  }
  for(int i = 0; i < l; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }
  for(int i = 0; i < n; ++i) {
    if(marc[i] > 1) {
      puts("0");
      return 0;
    }
  }
  dij();
  return 0;
}