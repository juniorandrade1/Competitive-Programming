#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int N = 51;

template <typename FTYPE, typename CTYPE> 
class MinCostMaxFlow {
private:
  const CTYPE COSTINF = numeric_limits<CTYPE>::max() / 2.0; 
  const FTYPE FLOWINF = numeric_limits<FTYPE>::max() / 2.0;
  const CTYPE eps = (CTYPE)(1e-9);
  struct Edge {
    int to;
    FTYPE cap;
    CTYPE cost;
    Edge(int a, FTYPE cp, CTYPE ct) { to = a; cap = cp; cost = ct; }
  };
  int n, sta, fin;
  vector< vector< int > > adj;
  vector< Edge > edge;
  vector< FTYPE > flow;
  vector< CTYPE > dist;
  vector< int > prv, eIdx;
  pair<FTYPE, CTYPE> dijkstra() { 
    fill(dist.begin(), dist.end(), COSTINF);
    priority_queue< pair< CTYPE, int > > q; q.push(make_pair(0, sta));
    dist[sta] = 0;
    flow[sta] = FLOWINF;
    while(!q.empty()) {
      pair< CTYPE, int >foo = q.top(); q.pop();
      int x = foo.second;
      CTYPE d = -foo.first;
      for(size_t a = 0; a < adj[x].size(); ++a) {
        int ind = adj[x][a];
        int y = edge[ind].to;
        if(!edge[ind].cap || dist[y] - dist[x] - edge[ind].cost <= eps) continue;
        dist[y] = dist[x] + edge[ind].cost;
        q.push(make_pair(-dist[y], y));
        prv[y] = x;
        eIdx[y] = ind;
        flow[y] = min(flow[x], edge[ind].cap);
      }
    }
    if(dist[fin] == COSTINF) return make_pair(FLOWINF, COSTINF);
    pair<FTYPE, CTYPE> ret = make_pair(flow[fin], 0);
    for(int cur = fin; cur != sta; cur = prv[cur]) {
      int ind = eIdx[cur];
      edge[ind].cap -= flow[fin];
      edge[ind ^ 1].cap += flow[fin];
      ret.second += flow[fin] * edge[ind].cost; 
    }
    return ret;
  }
public:
  MinCostMaxFlow(int _n, int _sta, int _fin) {
    n = _n;
    sta = _sta;
    fin = _fin;
    adj.resize(n);
    flow.resize(n);
    dist.resize(n);
    prv.resize(n);
    eIdx.resize(n);
  }
  void addEdge(int u, int v, FTYPE flw, CTYPE cst) {
    adj[u].push_back(edge.size());
    edge.push_back(Edge(v, flw, cst));
    adj[v].push_back(edge.size());
    edge.push_back(Edge(u, 0, -cst));
  }
  pair<FTYPE, CTYPE> mcmf() {
    pair<FTYPE, CTYPE> ret = make_pair(0, 0), got;
    while(fabs((got = dijkstra()).first - FLOWINF) > eps) {
      ret.first += got.first;
      ret.second += got.second;
    }
    return ret;
  }
};



void dfs(vector< vector< ii > > &g, vector< bool > &vis, int x) {
  if(vis[x]) return;
  vis[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].first;
    dfs(g, vis, y);
  }
}

inline void main2() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector< vector< ii > > g(n, vector< ii >());
  vector< vector< int > > floyd(n, vector< int >(n, 0));
  vector< int > deg(n, 0);
  vector< bool > vis(n, 0);
  ll sum = 0;
  for(int i = 0; i < m; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
    deg[a]--;
    deg[b]++;
    g[a].pb(mp(b, c));
    floyd[a][b] = 1;
    sum += (ll)c;
  }
  for(int i = 0; i < n; ++i) floyd[i][i] = 1;
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) floyd[i][j] |= (floyd[i][k] & floyd[k][j]);
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(floyd[i][j] == 0) {
    printf("-1\n");
    return;
  }
  int sta = n, fin = n + 1;
  MinCostMaxFlow<int, double> flowGraph(n + 2, sta, fin);
  int needFlow = 0;
  for(int x = 0; x < n; ++x) {
    if(deg[x] > 0) flowGraph.addEdge(sta, x, deg[x], 0);
    if(deg[x] < 0) {
      flowGraph.addEdge(x, fin, -deg[x], 0);
      needFlow -= deg[x];
    }
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].first;
      ll w = g[x][i].second;
      flowGraph.addEdge(x, y, INF, w);
    }
  }
  pair<int, double>sol = flowGraph.mcmf();
  if(sol.first != needFlow) puts("-1");
  else printf("%lld\n", sum + (ll)(0.5 + sol.second));
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}