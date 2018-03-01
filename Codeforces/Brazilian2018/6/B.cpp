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

 typedef ll FTYPE;

 const int MAXV = 100000; 
 const FTYPE FINF = LINF;

struct Edge {
  int to;
  FTYPE cap;
  Edge(int t, FTYPE c) { to = t; cap = c; }
};

vector<int> adj[MAXV];
vector<Edge> edge;
int ptr[MAXV], dinic_dist[MAXV];
// Inserts an edge u->v with capacity c

inline void add_edge(int u,int v,FTYPE c) {
  adj[u].push_back(edge.size());
  edge.push_back(Edge(v,c));
  adj[v].push_back(edge.size());
  edge.push_back(Edge(u,0)); // modify to Edge(u,c) if graph is non-directed
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

inline void dinic_clear() {
  for(int a=0;a<MAXV;++a) adj[a].clear();
  edge.clear();
}

const int N = 55;

int n, m;
char s[N][N];
int v[N][N];

int main() {
  int source = MAXV - 2, target = MAXV - 1;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    v[x - 1][y - 1] = 1;
  }
  int fl = 0, fr = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int gx = (i * m + j);
      if(v[i][j]) continue;
      if((i + j) % 2 == 0) add_edge(source, gx, 1), fl++;
      else add_edge(gx, target, 1), fr++;
      if((i + j) & 1) continue;
      for(int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= n) continue;
        if(v[x][y]) continue;
        int gy = (x * m + y);
        add_edge(gx, gy, 1);
      }
    }
  }
  printf("%d %d\n", fl, fr);
  ll mf = dinic(source, target);
  if(mf == fl && mf == fr) {
    puts("Yes");
  }
  else puts("No");
  return 0;
} 