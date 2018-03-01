#include <bits/stdc++.h>

using namespace std;

template <typename FTYPE> 
class MaxFlow {
private:
  const FTYPE FLOWINF = numeric_limits<FTYPE>::max() / 2.0;
  const FTYPE eps = (FTYPE)(1e-9);
  struct Edge {
    int to;
    FTYPE cap;
    Edge(int a, FTYPE cp) { to = a; cap = cp; }
  };
  int n, sta, fin;
  vector< Edge > edge;
  vector< vector< int > > adj;
  vector< int > ptr;
  vector< int > dist;
  vector< int > que;
  bool bfs() {
    int sq = 0, ed = 0;
    fill(dist.begin(), dist.end(), -1);
    que[ed++] = sta; dist[sta] = 0; 
    while(sq != ed) {
      int x = que[sq++];
      for(int i = 0; i < (int)adj[x].size(); ++i) {
        int ind = adj[x][i];
        int y = edge[ind].to;
        if(dist[y] == -1 && edge[ind].cap > eps) {
          dist[y] = dist[x] + 1;
          que[ed++] = y;
        }
      }
    }
    return dist[fin] != -1;
  }
  FTYPE dfs(int x, FTYPE f) {
    if(x == fin) return f;
    while(ptr[x] < adj[x].size()) {
      int ind = adj[x][ptr[x]];
      int y = edge[ind].to;
      if(dist[y] == dist[x] + 1 && edge[ind].cap > eps) {
        FTYPE foo = dfs(y, min(f, edge[ind].cap));
        if(foo > 0) {
          edge[ind].cap -= foo;
          edge[ind ^ 1].cap += foo;
          return foo;
        }
      }
      ptr[x]++;
    }
    return 0;
  }
public:
  MaxFlow(int _n, int _sta, int _fin) {
    n = _n;
    sta = _sta;
    fin = _fin;
    ptr.resize(n);
    adj.resize(n);
    dist.resize(n);
    que.resize(n);
  }
  void addEdge(int u, int v, FTYPE flw) {
    adj[u].push_back(edge.size());
    edge.push_back(Edge(v, flw));
    adj[v].push_back(edge.size());
    edge.push_back(Edge(u, 0));
  }
  FTYPE dinic() {
    FTYPE totFlow = 0, got = 0;
    while(bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      while((got = dfs(sta, FLOWINF)) > eps) totFlow += got;
    }
    return totFlow;
  }

  vector< long long > getDiffEdge() {
    vector< long long > sol(edge.size() / 2);
    for(int i = 1; i < edge.size(); i += 2) sol[i / 2] = edge[i].cap;
    return sol;
  } 
};

int main() {
  freopen("cooling.in", "r", stdin);
  freopen("cooling.out", "w", stdout);
  int n, m; scanf("%d %d", &n, &m);
  vector< int > deg(n, 0);
  int sta = n;
  int fin = n + 1;
  MaxFlow< long long > graph(n + 2, sta, fin);
  vector< long long > sol(m, 0);
  for(int i = 0; i < m; ++i) {
    int x, y, l, u; scanf("%d %d %d %d", &x, &y, &l, &u); x--; y--;
    deg[x] += l;
    deg[y] -= l;
    sol[i] += l;
    graph.addEdge(x, y, u - l);
  }
  int need = 0;
  for(int i = 0; i < n; ++i) {
    if(deg[i] < 0) {
      graph.addEdge(sta, i, -deg[i]);
    }
    else {
      graph.addEdge(i, fin, deg[i]);
      need += deg[i];
    }
  }
  int flw = graph.dinic();
  if(need != flw) {
    puts("NO");
    return 0;
  }
  else {
    puts("YES");
    vector< long long > foo = graph.getDiffEdge();
    for(int i = 0; i < m; ++i) {
      printf("%lld\n", sol[i] + foo[i]);
    }
    return 0;
  }
  return 0;
}