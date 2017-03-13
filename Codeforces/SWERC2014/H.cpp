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

const int N = 1010;

int n, p, s, t;
ll pd[N][N][2];
vii g[N];

struct state {
  ll x, q, op, w;
  state(){};
  state(ll _x, ll _q, ll _op, ll _w) {
    x = _x;
    q = _q;
    w = _w;
    op = _op;
  }
  bool operator < (state other) const {  
    return w > other.w;
  }
};

int swerc[N];

inline bool go(ll tax) {
  ll minTime = LINF;
  ll minTimeNop = LINF;
  for(int i = 1; i < n; ++i) {
    minTime = min(minTime, pd[t][i][0] + (i) * tax);
    minTimeNop = min(minTimeNop, pd[t][i][1] + (i) * tax);
  }
  //debug("%lld %lld\n", minTime, minTimeNop);
  return minTimeNop < minTime;
}

int main() {
  scanf("%d %d %d %d", &n, &p, &s, &t); s--; t--;
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) pd[i][j][0] = pd[i][j][1] = LINF;
  for(int i = 0; i < p; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    g[x - 1].pb(mp(y - 1, w));
    g[y - 1].pb(mp(x - 1, w));
  }
  int m; scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x); swerc[x - 1] = 1;
  }

  
  pd[s][0][1] = 0;
  pq< state > q; q.push(state(s, 0, 1, 0));
  
  while(!q.empty()) {
    state f = q.top(); q.pop();
    if(f.q == n) continue;
    if(pd[f.x][f.q][f.op] != f.w) continue;
     for(int i = 0; i < g[f.x].size(); ++i) {
      int y = g[f.x][i].F;
      ll w = g[f.x][i].S;
      int qn = f.q + 1;
      int op = (f.op & swerc[y]);
      if(pd[y][qn][op] > pd[f.x][f.q][f.op] + w) {
        pd[y][qn][op] = pd[f.x][f.q][f.op] + w;
        q.push(state(y, qn, op, pd[y][qn][op]));
      }
    }
  }

  ll minTime = LINF;
  for(int i = 0; i < n; ++i) {
    minTime = min(minTime, pd[t][i][0]);
  }  

  int impossible = true;
  for(int i = 0; i < n; ++i) {
    if(pd[t][i][1] <= minTime) impossible = false;
  }

  if(impossible) {
    puts("Infinity");
    exit(0);
  }
  
  ll lo = 0, hi = 10000000000000000LL;
  while(lo < hi) {
    ll mid = (lo + hi + 1) >> 1;
    if(go(mid)) lo = mid;
    else hi = mid - 1;
  }

  if(go(lo)) printf("%lld\n", lo);
  else printf("Impossible\n");



  


  return 0;
}