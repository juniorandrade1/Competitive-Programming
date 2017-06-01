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

const int N = 101;

typedef ll FTYPE;

const int MAXV = 101; 
const FTYPE FINF = LINF;

struct Edge {
  int to;
  FTYPE cap;
  Edge(int t, FTYPE c) { to = t; cap = c; }
};

vector<int> adj[MAXV];
vector<Edge> edge;

int ptr[MAXV], dinic_dist[MAXV];
inline void add_edge(int u,int v,FTYPE c) {
  adj[u].push_back(edge.size());
  edge.push_back(Edge(v,c));
  adj[v].push_back(edge.size());
  edge.push_back(Edge(u,0));
}

bool dinic_bfs(int _s,int _t) {
  memset(dinic_dist,-1,sizeof(dinic_dist));
  dinic_dist[_s] = 0;
  queue<int> q;
  q.push(_s);
  while(!q.empty() && dinic_dist[_t] == -1) {
    int v = q.front();
    q.pop();
    for(size_t a=0;a<adj[v].size();++a) {
      int ind = adj[v][a];
      int nxt = edge[ind].to;
      if(dinic_dist[nxt] == -1 && edge[ind].cap) {
        dinic_dist[nxt] = dinic_dist[v] + 1;
        q.push(nxt);
      }
    }
  }
  return dinic_dist[_t] != -1;
}

FTYPE dinic_dfs(int v,int _t,FTYPE flow) {
  if(v == _t) return flow;
  for(int &a = ptr[v];a<(int)adj[v].size();++a) {
    int ind = adj[v][a];
    int nxt = edge[ind].to;
    if(dinic_dist[nxt] == dinic_dist[v] + 1 && edge[ind].cap) {
      FTYPE got = dinic_dfs(nxt,_t,min(flow,edge[ind].cap));
      if(got) {
        edge[ind].cap -= got;
        edge[ind^1].cap += got;
        return got;
      }
    }
  }
  return 0;
}

FTYPE dinic(int _s,int _t) {
  FTYPE ret = 0, got;
  while(dinic_bfs(_s,_t)) {
    memset(ptr,0,sizeof(ptr));
    while((got = dinic_dfs(_s,_t,FINF))) ret += got;
  }
  return ret;
}

int n, m;

inline void dinic_clear() {
  for(int a=0;a<n;++a) adj[a].clear();
  edge.clear();
}

vector< ii > ed1000son;

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    ed1000son.clear();
    for(int i = 0; i < m; ++i) {
      int x, y;
      char a, b, c;
      scanf(" %c %d %c %d %c", &a, &x, &b, &y, &c);
      ed1000son.pb(mp(x, y));
    }
    if(n <= 1) {
      puts("0");
      continue;
    }
    ll ans = LINF;
    for(int i = 1; i < n; ++i) {
      dinic_clear();
      for(int j = 0; j < m; ++j) {
        add_edge(ed1000son[j].F, ed1000son[j].S, 1);
        add_edge(ed1000son[j].S, ed1000son[j].F, 1);
      }
      ans = min(ans, dinic(0, i));
    }
    printf("%lld\n", ans);
  }
  return 0;
}