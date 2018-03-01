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

vector< ii > g[N];
int vis[N];
int n, x;

void dfs(int x) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].F;
    if(vis[y] == -1) {
      vis[y] = (vis[x] ^ g[x][i].S);
      dfs(y);
    }
  }
}



bool go(multiset< ii > &my, ll s) {
  if(my.size() == 1) return (*my.begin()).F == 0;
  ii a = *my.begin(); my.erase(my.begin());
  ii b;
  if(s % 2 == 0 && s + a.F == s / 2) { //equalSet
    my.insert(a);
    while(my.size() >= 2) {
      a = *my.begin(); my.erase(my.begin());
      b = *my.begin(); my.erase(my.begin());
      ii b = *my.begin(); my.erase(my.begin());
      g[a.S].pb(mp(b.S, 1));
      g[b.S].pb(mp(a.S, 1));
      ll d = a.F + b.F;
      my.insert(mp(d, a.S));
    }
    return true;
  }
  else {
    b = *my.begin(); my.erase(my.begin());
    ii axd = ii(a.F + b.F, a.S);
    ii axs = ii(a.F - b.F, a.S);
    g[a.S].pb(ii(b.S, 1));
    g[b.S].pb(ii(a.S, 1));
    my.insert(axd);
    if(go(my, s + 2 * b.F)) return true;
    my.erase(my.find(axd));
    g[b.S].pop_back();
    g[a.S].pop_back();

    g[a.S].pb(ii(b.S, 0));
    g[b.S].pb(ii(a.S, 0));
    my.insert(axs);
    if(go(my, s)) return true;
    my.erase(my.find(axs));
    g[b.S].pop_back();
    g[a.S].pop_back();

    my.insert(b);
  }
  my.insert(a);
  return false;
}

vector< int > bestPartition(vector< int > &s) {
  multiset< ii > my;
  ll sum = 0;
  for(int i = 0; i < s.size(); ++i) {
    sum += s[i];
    my.insert(mp(-s[i], s[i]));
  }
  bool ok = go(my, sum);
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
  for(int i = 1; i <= n; ++i) {
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

  vector< int > v;
  s /= 2;
  ll w = s;
  for(int i = n; i >= 1; --i) if(i != x) v.pb(i);
  vector< int > sol = bestPartition(v);
  for(int i = 0; i < sol.size(); ++i) w -= sol[i];
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
  
  for(int i = n; i >= 1; --i) {
    if(ok[i] == 2) continue;
    if(s >= i) {
      s -= i;
      ok[i] = 1;
    }
  }
  if(!s) {
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