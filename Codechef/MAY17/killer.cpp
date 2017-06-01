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

const int N = 5012;

vi g[100001];
int n;
ll c[100001], h[100001], cc[100001];
bitset<N>memo[100001];
ll pd[N][N];
ll treeDepth;
ll depth[100001];
ll csum[100001];

ll dp[100001];

void dfs(int x, int ult, int sz, ll sum) {
  if(memo[x][sz]) return;
  memo[x][sz] = 1;
  ll foo = (c[x] * c[x] * sz + c[x] * sum - h[x]);
  for(int i = 0; i < g[x].size(); ++i){
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x, 1, treeDepth - depth[y]);
    dfs(y, x, sz + 1, sum  + treeDepth - depth[y]);
    foo += pd[y][1];
  }
  pd[x][sz] = foo;
  foo -= (c[x] * c[x] * sz + c[x] * sum - h[x]);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    pd[x][sz] = min(pd[x][sz], foo - pd[y][1] + pd[y][sz + 1]);
  }
}



void findDepth(int x, int ult) {
  treeDepth = max(treeDepth, depth[x]);
  memo[x].reset();
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    depth[y] = depth[x] + 1;
    findDepth(y, x);
  }
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i <= n; ++i) g[i].clear();
  ll hSum = 0;
  for(int i = 1; i <= n; ++i) scanf("%lld %lld", h + i, c + i), cc[i] = c[i] * c[i];
  bool justIPlusOne = true;
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    if(a > b) swap(a, b);
    if(a + 1 != b) justIPlusOne = false;
    g[a].pb(b);
    g[b].pb(a);
  }
  if(!justIPlusOne) {
    treeDepth = 0;
    findDepth(1, 1);
    dfs(1, 1, 1, treeDepth);
    printf("%lld\n", pd[1][1]);
  }
  else {
    treeDepth = n;
    dp[0] = 0;
    csum[0] = 0;
    for(int i = 1; i <= n; ++i) csum[i] = (n - i) + csum[i - 1];
    for(int i = 1; i <= n; ++i) {
      dp[i] = LINF;
      for(int j = 1; j <= i; ++j) {
        ll a = dp[j - 1] - cc[i] * j - c[i] * csum[j - 1]; 
        dp[i] = min(dp[i], a);
      }
      dp[i] += cc[i] * i + cc[i] + c[i] * csum[i] - h[i];
    }
    printf("%lld\n", dp[n]);
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}