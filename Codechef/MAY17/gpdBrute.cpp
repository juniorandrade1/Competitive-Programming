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

const int N = 5050;

vii g[N];
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

int p[N];
int path[N];

void dfs(int x, int dad, int lst) {
  path[x] = lst;
  p[x] = dad;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].F, w = g[x][i].S;
    if(y == dad) continue;
    dfs(y, x, w);
  }
}

inline ll getMaxAnswer(int u, int k) {
  ll ans = 0;
  int at = root[u];
  for(int i = BIT; i >= 0; --i) {
    int b = ((k >> i) & 1);
    if(tr[at][!b] != -1) {
      ans ^= (1LL << i);
      at = tr[at][!b];
    }
    else at = tr[at][b];
  }
  return ans;
}

inline ll getMinAnswer(int u, int k) {
  ll ans = 0;
  int at = root[u];
  for(int i = BIT; i >= 0; --i) {
    int b = ((k >> i) & 1);
    if(tr[at][b] != -1) {
      at = tr[at][b];
    }
    else {
      ans ^= (1LL << i);
      at = tr[at][!b];
    }
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  scanf("%d %d", &r, &key);
  for(int i = 0; i + 1 < n; ++i) {
    int u, v, k; scanf("%d %d %d", &u, &v, &k);
    u = getIdx(u);
    v = getIdx(v);
    g[u].pb(mp(v, k));
    g[v].pb(mp(u, k));
  }
  int last_answer = 0;
  for(int i = 0; i < q; ++i) {
    int t; scanf("%d", &t);
    t ^= last_answer;
    if(t == 0) {
      int v, u, k; scanf("%d %d %d", &v, &u, &k);
      u ^= last_answer;
      v ^= last_answer;
      k ^= last_answer;
      if(idxNode.find(u) == idxNode.end()) swap(u, v);
      u = getIdx(u);
      v = getIdx(v);
      g[u].pb(mp(v, k));
      g[v].pb(mp(u, k));
    }
    else {
      int v, k; scanf("%d %d", &v, &k);
      v ^= last_answer;
      k ^= last_answer;

      ll min_answer = getMinAnswer(getIdx(v), k);
      ll max_answer = getMaxAnswer(getIdx(v), k);
      printf("%lld %lld\n", min_answer, max_answer);
      last_answer = (min_answer ^ max_answer);
    }
  }

  return 0;
}
