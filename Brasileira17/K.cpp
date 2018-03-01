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

const int N = 25;

char s[N][N];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  int inFlow = 0, outFlow = 0;
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    scanf(" %c", &s[i][j]);
    int w = (s[i][j] == '-') ? 2 : 1;
    if((i + j) & 1) {
      add_edge(i * m + j, target, w);
      inFlow += w;
    }
    else {
      add_edge(source, i * m + j, w);
      outFlow += w;
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      for(int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        int nx = (i * m + j), ny = (x * m + y);
        if((i + j) & 1) swap(nx, ny);
        add_edge(nx, ny, 1);
      }
    }
  }
  int flw = dinic(source, target);
  puts(flw == inFlow && flw == outFlow ? "Y" : "N");
  return 0;
}