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

#define V 31
 
 
bool isSafe (int v, bool graph[V][V], int color[], int c) {
  for (int i = 0; i < V; i++) if (graph[v][i] && c == color[i]) return false;
  return true;
}
 
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
  if (v == V) return true;
  for (int c = 1; c <= m; c++) {
    if (isSafe(v, graph, color, c)) {
       color[v] = c;
       if (graphColoringUtil (graph, m, color, v+1) == true) return true;
       color[v] = 0;
    }
  }
  return false;
}

bool graphColoring(bool graph[V][V], int m) {
  int *color = new int[V];
  for (int i = 0; i < V; i++) color[i] = 0;
  return graphColoringUtil(graph, m, color, 0);
}
 

bool g[V][V];
int n, m;

inline void main2() {
  scanf("%d %d", &n, &m);
  memset(g, 0, sizeof g);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  int numColors = 1;
  while(graphColoring(g, numColors) == false) numColors++;
  printf("%d\n", numColors);
}
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
