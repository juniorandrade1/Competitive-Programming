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

typedef ll FTYPE;
const int MAXV = 2000000;
const FTYPE FINF = LINF;

struct Edge {
  int to;
  FTYPE cap;
  Edge(int t, FTYPE c) { to = t; cap = c; }
};

map< ii, bool > hasEdge;

vector<int>adj[MAXV];
vector<Edge> edge;
int ptr[MAXV], dinic_dist[MAXV];

inline void add_edge(int u,int v,FTYPE c) {
  if(hasEdge[ii(u, v)]) return;
  hasEdge[ii(u, v)] = 1;
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

int n, m, k;
const int SOURCE = MAXV - 2, SINK = MAXV - 1;
const int N = 2500;

ll v[N][N];
ll tr[4 * 4 * N];
int nodeCounter = 0;

void build(int no, int li, int ri, int lj, int rj) {
  nodeCounter = max(nodeCounter, no) + 1;
  if(li > ri || lj > rj) return;
  if(li == ri && lj == rj) {
    tr[no] = v[li][lj];
    return;
  }
  int nxt = (no * 4);
  int mi = (li + ri) >> 1;
  int mj = (lj + rj) >> 1;
  build(nxt - 2, li, mi, lj, mj);
  build(nxt - 1, li, mi, mj + 1, rj);
  build(nxt + 0, mi + 1, ri, lj, mj);
  build(nxt + 1, mi + 1, ri, mj + 1, rj);

  add_edge(nxt - 2, no, tr[nxt - 2]);
  add_edge(nxt - 1, no, tr[nxt - 1]);
  add_edge(nxt + 0, no, tr[nxt + 0]);
  add_edge(nxt + 1, no, tr[nxt + 1]);
  tr[no] = tr[nxt - 2] + tr[nxt - 1] + tr[nxt + 0] + tr[nxt + 1];
}

inline void go(int no, int li, int ri, int lj, int rj, int t, int b, int l, int r, int idx) {
  if(ri < li || rj < lj) return;
  if(ri < t || li > b || rj < l || lj > r) return;
  if(li >= t && ri <= b && lj >= l && rj <= r) {
    add_edge(idx, no, LINF);
    return;
  }
  int nxt = (no * 4);
  int mi = (li + ri) >> 1;
  int mj = (lj + rj) >> 1;

  go(nxt - 2, li, mi, lj, mj, t, b, l, r, idx);
  go(nxt - 1, li, mi, mj + 1, rj, t, b, l, r, idx);
  go(nxt + 0, mi + 1, ri, lj, mj, t, b, l, r, idx);
  go(nxt + 1, mi + 1, ri, mj + 1, rj, t, b, l, r, idx);

}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%lld", &v[i][j]);
  build(1, 0, n - 1, 0, m - 1);
  add_edge(1, SINK, tr[1]);


  for(int i = 0; i < k; ++i) {
    int t, b, l, r, x;
    scanf("%d %d %d %d %d", &t, &b, &l, &r, &x);
    go(1, 0, n - 1, 0, m - 1, t - 1, b - 1, l - 1, r - 1, i + nodeCounter + 1);
    add_edge(SOURCE, i + nodeCounter + 1, x);
  }
  printf("%lld\n", dinic(SOURCE, SINK));
  return 0;
}