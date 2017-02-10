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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 200020;

multiset<ii> g[N];
int deg[N];
int n, m;
int finalPath[N];
int fin = 0;
ii allEdges[N];
int rev[N];

map< ii, int > a;

inline void addEdge(int x, int y, int id) {
  g[x].insert(ii(y, 0));
  g[y].insert(ii(x, 1));
  deg[x]++;
  deg[y]++;
  a[ii(x, y)] = id;
}

stack<int>s; 

inline void findPath(int root) {
  s.push(root);
  while(!s.empty()) {
    int x = s.top();
    if(deg[x] == 0) {
      finalPath[fin++] = x;
      s.pop();
      continue;
    }
    ii foo = *g[x].begin();
    int y = foo.F, t = foo.S;
    int id = 0;
    if(t == 0) id = a[ii(x, y)];
    else id = a[ii(y, x)];
    s.push(y);
    deg[x]--;
    deg[y]--;
    g[x].erase(ii(y, t));
    g[y].erase(ii(x, 1 - t));
  }
}

int vis[N];

void dfs(int x) {
  if(vis[x]) return;
  vis[x] = 1;
  for(multiset<ii>::iterator it = g[x].begin(); it != g[x].end(); it++) dfs(it->F);
}


int main() {
  scanf("%d %d", &n, &m);
  if(n == 1) {
    puts("NO");
    return 0;
  }
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    addEdge(a, b, i);
    allEdges[i] = ii(a, b);
  }
  for(int i = 1; i <= n; ++i){
    if(deg[i] & 1) {
      puts("NO");
      return 0;
    }
  }
  
  dfs(1);
  for(int i = 1; i <= n; ++i) {
    if(vis[i] == 0) {
      puts("NO");
      return 0;
    }
  }
  findPath(1);

  for(int i = 0; i + 1 < fin; ++i) {
    int x = finalPath[i], y = finalPath[i + 1];
    if(a.find(ii(x, y)) != a.end()) continue;
    rev[a[ii(y, x)]] = 1; 
  }

  puts("YES");
  for(int i = 0; i < m; ++i) {
    if(rev[i] == 0) printf("%lld %lld\n", allEdges[i].S, allEdges[i].F);
    else printf("%lld %lld\n", allEdges[i].F, allEdges[i].S);
  }

  return 0;
}