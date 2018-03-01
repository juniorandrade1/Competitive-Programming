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

#define pi acos(-1.0)

const int N = 75;

struct Node {
  int x, y;
  Node(){
    x = 0;
    y = INF;
  };
  Node(int _x, int _y) {
    x = _x;
    y = _y;
  }
  bool operator < (Node o) const {
    if(x != o.x) return x < o.x;
    else return y > o.y;
  }
};

int n, m;
int g[N][N];
int ng[N][N];

void setTable() {
  for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
    g[i][j] = INF;
    if(i == j) g[i][j] = 0;
  }
}

Node getAns(int a, int b) {
  Node ret; 
  for(int x = 0; x < n; ++x) {
    for(int y = 0; y < n; ++y) {
      ng[x][y] = g[x][y];
      ng[x][y] = min(ng[x][y], ng[x][a] + ng[b][y]);
      ng[x][y] = min(ng[x][y], ng[x][b] + ng[a][y]);
      ret.x = max(ret.x, ng[x][y]);
    }
  }
  for(int x = 0; x < n; ++x) {
    for(int y = 0; y < n; ++y) {
      if(g[x][y] <= ret.x) continue;
      ret.y = min(ret.y, ret.x - ng[x][y]);
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); a--; b--;
    g[a][b] = min(g[a][b], c);
    g[b][a] = min(g[b][a], c);
  }
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  Node sol = Node(INF, INF);
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j ) sol = min(sol, getAns(i, j));
  if(sol.x == INF) sol.x = -1;
  if(sol.y == INF) sol.y = -1;
  printf("%d %d\n", sol.x, sol.y);
  return 0;
}