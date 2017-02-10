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
#define PI acos(-1.0)
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 200010;

class UF {
  public:
  int *id, cnt, *sz;
// Create an empty merge find data structure with N isolated sets.
  UF(int N) {
      cnt = N; id = new int[N]; sz = new int[N];
      for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
  ~UF() { delete[] id; delete[] sz; }

// Return the id of component corresponding to object p.
  int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
      return root;
  }
  // Replace sets containing x and y with their merge.
  void merge(int x, int y) {
      int i = find(x); int j = find(y); if (i == j) return;
      // make smaller root point to larger one
      if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
      else { id[j] = i, sz[i] += sz[j]; }
      cnt--;
  }
  // Are objects x and y in the same set?
  bool connected(int x, int y) { return find(x) == find(y); }
  // Return the number of disjoint sets.
  int count() { return cnt; }
};

UF uf(N);
map<string, int> _nor;

int getIdx(string _s) {
  return _nor[_s];
}

char s[N], t[N];
int n, m, q;

int cor[N];
vii g[N];

void bfs(int st) {
  queue<int>q; q.push(st);
  cor[st] = 0;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F, op = g[x][i].S;
      if(cor[y] == -1) {
        cor[y] = cor[x] ^ op;
        q.push(y);
      }
      assert((cor[y] ^ op) == cor[x]);
    }
  }
}

set<int>vis;

void changeColor(int x) {
  if(vis.find(x) != vis.end()) return;
  vis.insert(x);
  cor[x] ^= 1;
  for(int i = 0; i < g[x].size(); ++i) changeColor(g[x][i].F);
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    _nor[(string)s] = i;
  }
  memset(cor, -1, sizeof cor);
  for(int i = 0; i < m; ++i) {
    int op;
    scanf("%d %s %s", &op, s, t);
    int nop = 0;
    op--;
    int x = getIdx((string)s);
    int y = getIdx((string)t);
    if(cor[x] == -1 && cor[y] == -1) {
      cor[x] = 0;
      cor[y] = op;
    }
    else if(cor[x] != -1 && cor[y] == -1) cor[y] = cor[x] ^ op;
    else if(cor[y] != -1 && cor[x] == -1) cor[x] = cor[y] ^ op;
    else if(cor[x] == cor[y]) {
      if(op == 1) {
        if(uf.connected(x, y)) nop = 1;
        else {
          int fx = uf.find(x);
          int fy = uf.find(y);
          vis.clear();
          if(uf.sz[fx] < uf.sz[fy]) changeColor(x);
          else changeColor(y);
        }
      }
    }
    else {
      if(op == 0) {
        if(uf.connected(x, y)) nop = 1;
        else {
          int fx = uf.find(x);
          int fy = uf.find(y);
          vis.clear();
          if(uf.sz[fx] < uf.sz[fy]) changeColor(x);
          else changeColor(y);
        }
      }
    }
    if(nop) puts("NO");
    else {
      puts("YES");
      uf.merge(x, y);
      g[x].pb(mp(y, op));
      g[y].pb(mp(x, op));
    }
  }
  memset(cor, -1, sizeof cor);
  for(int i = 0; i < n; ++i) if(cor[i] == -1) bfs(i);
  while(q--) {
    scanf(" %s %s", s, t);
    int x = getIdx((string)s);
    int y = getIdx((string)t);
    if(!uf.connected(x, y)) puts("3");
    else if(cor[x] == cor[y]) puts("1");
    else puts("2");
  }
  return 0;
}