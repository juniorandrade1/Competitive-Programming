typedef long long FTYPE;

const FTYPE FINF = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
  int nxt;
  FTYPE cap;
  Edge(){};
  Edge(int _nxt, FTYPE _cap) {
    nxt = _nxt;
    cap = _cap;
  }
};

const int N = 100010;

vector< Edge > edges;
vector< int > adj[N];
int dist[N];

inline void addEdge(int x, int y, FTYPE cap) {
  adj[x].push_back(edges.size());
  edges.push_back(Edge(y, cap));
  adj[y].push_back(edges.size());
  edges.push_back(Edge(x, 0));
}

inline bool dinicBfs(int _s, int _t) {
  memset(dist, -1, sizeof dist);
  queue<int>q; q.push(_s); dist[_s] = 0;
  while(!q.empty()){
    int x = q.front(); q.pop();
    for(int i = 0; i < adj[x].size(); ++i) {
      int ed = adj[x][i];
      int y = edges[ed].nxt;
      if(dist[y] == -1 && edges[ed].cap) {
        dist[y] = dist[x] + 1;
        q.push(y);
      }
    }  
  }
  return dist[_t] != -1;
}

FTYPE dinicDfs(int x, int t, FTYPE got = FINF) {
  if(x == t) return got;
  for(int i = 0; i < adj[x].size(); ++i) {
    int ed = adj[x][i];
    int y = edges[ed].nxt;
    if(dist[y] + 1 == dist[x] && edges[ed].cap) {
      got = min(got, dinicDfs(y, t, min(got, edges[ed].cap)));
      if(got) {
        edges[ed].cap -= got;
        edges[ed ^ 1].cap += got;
        return got;
      }
    }
  }
  return 0;
}

FTYPE dinic(int _s, int _t) {
  FTYPE flow = 0;
  FTYPE got = 0;
  while(dinicBfs(_s, _t)) while((got = dinicDfs(_s, _t))) flow += got;
  return flow;
}

inline void dinicClear() {
  for(int i = 0; i < N; ++i) adj[i].clear();
  edges.clear();
}