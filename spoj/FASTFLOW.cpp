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

const int N = 5005;

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

vector< Edge > edges;
vector< int > adj[N];
int dist[N], ptr[N];

inline void addEdge(int x, int y, FTYPE cap) {
  adj[x].push_back(edges.size());
  edges.push_back(Edge(y, cap));
  adj[y].push_back(edges.size());
  edges.push_back(Edge(x, 0));
}

inline bool dinicBfs(int _s, int _t) {
  memset(dist, -1, sizeof dist);
  queue<int>q; q.push(_s); dist[_s] = 0;
  while(!q.empty() && dist[_t] == -1){
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
  while(ptr[x] < adj[x].size()) {
    int ed = adj[x][ptr[x]++];
    int y = edges[ed].nxt;
    if(dist[x] + 1 == dist[y] && edges[ed].cap) {
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
  while(dinicBfs(_s, _t)) {
    memset(ptr, 0, sizeof ptr);
    while((got = dinicDfs(_s, _t))) flow += got;
  }
  return flow;
}

inline void dinicClear() {
  for(int i = 0; i < N; ++i) adj[i].clear();
  edges.clear();
}

int main() {
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    dinicClear();
    for(int i = 0; i < m; ++i) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c);
      addEdge(a - 1, b - 1, c);
    }
    printf("%lld\n", dinic(0, n - 1));
  }
  return 0;
}
