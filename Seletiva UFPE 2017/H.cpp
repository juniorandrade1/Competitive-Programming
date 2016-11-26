#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
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
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 1000200;

vii g[N];
int n, m, k;
ll v[N];
ll type[N];
ll dis[N];

ll dij(int st, int fs) {
  pq< ii > q; q.push(ii(0, st));
  dis[st] = 0;
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.S;
    ll w = -foo.F;
    if(dis[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll cost = g[x][i].S;
      ll aux = cost + dis[x];
      ll newTime = aux;
      if(y != fs) newTime = ((aux + v[type[y]] - 1LL) / (v[type[y]])) * (v[type[y]]);
      if(dis[y] > newTime) {
        dis[y] = newTime;
        q.push(ii(-newTime, y));
      }
    }
  }
  return dis[fs];
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= k; ++i) scanf("%lld", v + i);
  for(int i = 0; i < m; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }
  for(int i = 0; i < n; ++i) scanf("%d", type + i), dis[i] = LINF;
  int s, t; scanf("%d %d", &s, &t);
  printf("%lld\n", dij(s - 1, t - 1));
  return 0;
}