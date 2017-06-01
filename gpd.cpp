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

const int N = 200000;

int tr[N][2];
int sz = 1;
vii g[N];
int root[N];


void build(int x, int key) {
  root[x] = sz;
  int at = 0;
  for(int i = 31; i >= 0; --i) {
    int b = ((x >> i) & 1);
    tr[at][b] = sz++;
    at = tr[at][b];
  }  
}

int go(int no, int x, int bit) {
  int NO = sz++;
  tr[NO][0] = tr[no][0]; tr[NO][1] = tr[no][1];
  if(bit == 0) return NO;
  int b = ((x >> bit) & 1);
  tr[NO][b] = go(tr[NO][b], x, bit - 1);
  return NO;
}

void dfs(int x, int dad, int need) {
  root[x] = go(root[dad], need, bit);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].F, w = g[x][i].S;
    if(dad == y) continue;
    dfs(y, x, w);
  }
}

int n, q;
int r, key;

/////////////////////////////////////////////
map<int, int>idxNode;
map<int, int>vltNode;
int nodeCounter = 0;
inline int getIdx(int x) {
  if(idxNode.find(x) == idxNode.end()) {
    idxNode[x] = nodeCounter;
    vltNode[nodeCounter++] = x;
  }
  return idxNode[x];
}
/////////////////////////////////////////////



int main() {
  memset(tr, -1, sizeof tr);

  scanf("%d %d", &n, &q);
  scanf("%d %d", &r, &key);

  for(int i = 0; i + 1 < n; ++i) {
    int u, v, k; scanf("%d %d %d", &u, &v, &k);
    int iu = getIdx(u);
    int iv = getIdx(v);
    g[u].pb(mp(v, k));
    g[v].pb(mp(u, k));
  }

  build(vltNode[r], key);
  for(int i = 0; i < g[vltNode[r]].size(); ++i) {
    int y = g[vltNode[r]][i].F, w = g[vltNode[r]][i].S;
    dfs(y, vltNode[r], w);
  }

  int last_answer = 0;


  for(int i = 0; i < q; ++i) {
    int t; scanf("%d", &t);
    t ^= last_answer;
    if(t == 0) {
      int v, u, k; scanf("%d %d %d", &u, &v, &k);
      u ^= last_answer;
      v ^= last_answer;
      k ^= last_answer;
    }
    else {
      int v, k; scanf("%d %d", &v, &k);
      debug("-> %d %d %d\n", t, v, k);
      v ^= last_answer;
      k ^= last_answer;
      int min_answer = 0;
      int max_answer = 0;
      last_answer = min_answer ^ max_answer;
    }
  }

  return 0;
}
