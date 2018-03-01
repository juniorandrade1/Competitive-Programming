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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

typedef ll FTYPE;

const int MAXV = 100010; 
const FTYPE FINF = LINF; 
const int source = MAXV - 2;
const int target = MAXV - 1;

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

inline void dinic_clear() {
  for(int a=0;a<MAXV;++a) adj[a].clear();
  edge.clear();
}

const int N = 101;

int n;
int a[N], b[N];
int m;
int h[N];

void solve(int x) {
  if(x == source || x == target) return;
  for(int i = 0; i < adj[x].size(); ++i) {
    int ind = adj[x][i];
    if(edge[ind ^ 1].cap == 0) {
      solve(edge[ind].to);
      if(edge[ind].to % 2 == 0 && edge[ind].to != source) printf("%d ", edge[ind].to / 2 + 1);
      return;
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
  }
  for(int i = 0; i < n; ++i) {
    if(a[i] == 0) add_edge(source, i * 2, 1);
    add_edge(i * 2, i * 2 + 1, 1);
    for(int j = 0; j < n; ++j) {
      if(i == j) continue;
      if(b[i] >= a[j]) add_edge(i * 2 + 1, j * 2, 1);
    }
  }
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    scanf("%d", h + i);
    for(int j = 0; j < n; ++j) {
      if(b[j] >= h[i]) add_edge(j * 2 + 1, i + 2 * n, 1);
    }
    add_edge(i + 2 * n, target, 1);
  }
  int go = dinic(source, target);
  debug("FLOW = %d\n", go);
  if(go < m) {
    printf("impossible");
    return 0;
  }
  for(int i = 0; i < m; ++i) {
    solve(i + 2 * n);
    printf("\n");
  }
  return 0;
}