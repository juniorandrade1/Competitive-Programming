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
 
//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////
 
const int N = 5050;
 
int n, b, s, r;
vii g[N];
vii rev[N];
ll dis[N];
 
void dijkstra(int st) {
  for(int i = 0; i <= n; ++i) dis[i] = LINF;
  dis[st] = 0;
  set<ii>s; s.insert(ii(0, st));
  while(s.size()) {
    ii foo = *s.begin(); s.erase(s.begin());
    int x = foo.S, w = foo.F;
    if(dis[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F, c = g[x][i].S;
      if(dis[y] > dis[x] + c) {
        dis[y] = dis[x] + c;
        s.insert(ii(dis[y], y));
      }
    }
  }
}

void dijkstra2(int st) {
  for(int i = 0; i <= n; ++i) dis[i] = LINF;
  dis[st] = 0;
  set<ii>s; s.insert(ii(0, st));
  while(s.size()) {
    ii foo = *s.begin(); s.erase(s.begin());
    int x = foo.S, w = foo.F;
    if(dis[x] != w) continue;
    for(int i = 0; i < rev[x].size(); ++i) {
      int y = rev[x][i].F, c = rev[x][i].S;
      if(dis[y] > dis[x] + c) {
        dis[y] = dis[x] + c;
        s.insert(ii(dis[y], y));
      }
    }
  }
}
 
ll cost[N];
ll pd[N][N];
ll sumCum[N];

void func(int k, int l, int r, int loool, int rr){
    if(l>r)
        return;
    int m = (l+r)/2;
    pd[m][k] = LINF;
    int xd;
    for(ll i = max(loool,m);i<=rr;i++){
        ll cu = ((sumCum[i+1]-sumCum[m])*(i-m));
        if(pd[m][k]>pd[i+1][k-1] + cu){
            pd[m][k] = pd[i+1][k-1] + cu;
            xd = i;
        }
    }
    func(k,l,m-1,loool,xd);
    func(k,m+1,r,xd,rr);
}
 
int main() {
  while(scanf("%d %d %d %d", &n, &b, &s, &r) != EOF) {
    for(int i = 0; i <= n; ++i) g[i].clear();
    for(int i = 0; i < r; ++i) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c);
      g[a].pb(mp(b, c));
      rev[b].pb(mp(a, c));
    }
    memset(cost, 0, sizeof cost);
    dijkstra(b + 1);  
    for(int i = 1; i <= b; ++i) cost[i - 1] = dis[i];
    dijkstra2(b + 1);
    for(int i = 1; i <= b; ++i) cost[i - 1] += dis[i];
    sort(cost, cost + b);
    sumCum[0] = 0;
    for(int i = 1;i<=b;i++) sumCum[i] = (sumCum[i-1]+cost[i-1]);
    for(int i = 0;i<=b+10;i++) for(int j = 0;j<=s+10;j++) pd[i][j] = LINF;
    for(int j = 0;j<=s+10;j++)pd[b][j] = 0;
    for(int i = 1;i<=s;i++) func(i,0,b-1,0,b-1);
    printf("%lld\n",pd[0][s]);
  } 
  return 0;
}