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
 
const int N = 1000001;
 
vector< int > g[N];
int vis[N];
int n, x;
 
void dfs(int x) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(vis[y] == -1) {
      vis[y] = 1 - vis[x];
      dfs(y);
    }
  }
}
 
vector< int > bestPartition(vector< int > &s) {
  multiset< ii > my;
  for(int i = 0; i < s.size(); ++i) my.insert(mp(-s[i], s[i]));
  while(my.size() >= 2) {
    ii a = *my.begin(); my.erase(my.begin());
    ii b = *my.begin(); my.erase(my.begin());
    g[a.S].pb(b.S);
    g[b.S].pb(a.S);
    int d = a.F - b.F;
    my.insert(mp(d, a.S));
  }
  vis[1 + (x == 1)] = 0;
  dfs(1 + (x == 1));
  vector< int > p;
  for(int i = 1; i <= n; ++i) {
    if(x == i) continue;
    if(vis[i] == 0) p.pb(i);
  }
  return p;
}
 
 
int ok[N];
 
inline void main2() {
  scanf("%d %d", &x, &n);
  for(int i = 0; i <= n; ++i) {
    ok[i] = 0;
    vis[i] = -1;
    g[i].clear();
  }
  ok[x] = 2;
  ll s = (ll)(n * (n + 1LL)) / 2LL - x;
  if(s & 1) {
    puts("impossible");
    return;
  }
  ll w = s / 2LL;
  vector< int > v;
  for(int i = 1; i <= n; ++i) if(i != x) v.push_back(i);
  vector< int > sol = bestPartition(v);
  //debug("BEST =");
  for(int i = 0; i < sol.size(); ++i) {
    //debug(" %d", sol[i]);
    w -= sol[i];
  }
  //debug("\n");
  if(!w) {
    for(int i = 1; i <= n; ++i) {
      if(i == x) ok[i] = 2;
      else ok[i] = 0;
    }
    for(int i = 0; i < sol.size(); ++i) ok[sol[i]] = 1;
    for(int i = 1; i <= n; ++i) printf("%d", ok[i]);
    printf("\n");
    return;
  }
  puts("impossible");
  return;
} 
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}  