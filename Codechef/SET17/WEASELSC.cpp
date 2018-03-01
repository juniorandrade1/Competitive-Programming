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

const int N = 100010;
const int K = 52;
const int M = 20;

ll v[N];
ll spt[N][M];
ll dp[2][N];
ll bst[N];
int n, k;

inline void process() {
  for(int j = 1; (1 << j) <= n; ++j) {
    for(int i = 1; i + (1 << j) - 1 <= n; ++i) spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
  }
}

inline ll query(int l, int r) {
  int sz = (r - l + 1);
  int lvl = 31 - __builtin_clz(sz);
  return min(spt[l][lvl], spt[r - (1 << lvl) + 1][lvl]);
}

void func(int l, int r, int bl, int br, int ak) {
  if(l > r) return;
  int i = (l + r) >> 1;
  int foo = (ak & 1);
  int bck = (foo ^ 1);
  int bst = -1;
  dp[foo][i] = 0;
  for(int j = bl; j <= i; ++j) {
    if(dp[foo][i] < dp[bck][j - 1] + (i - j + 1) * query(j, i)) {
      dp[foo][i] = dp[bck][j - 1] + (i - j + 1) * query(j, i);
      bst = j;
    }
  }
  func(l, i - 1, bl, bst, ak);
  func(i + 1, r, bst, br, ak);
}

inline void main2() {
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i), spt[i][0] = v[i];
  process();
  memset(dp[0], 0, sizeof dp[0]);
  k++;
  //for(int z = 1; z <= k; ++z) func(1, n, 1, n, z);
  ll ans = 0;
  for(int z = 1; z <= k; ++z) {
    int foo = (z & 1);
    int bck = ((z & 1) ^ 1);
    int j = 1;
    for(int i = 1; i <= n; ++i) {
      dp[foo][i] = dp[bck][j - 1] + (i - j + 1) * query(j, i);
      while(j < i && dp[foo][i] < dp[bck][j] + (i - j) * query(j + 1, i)) {
        dp[foo][i] = dp[bck][j] + (i - j) * query(j + 1, i);
        j++;
      } 
      ans = max(ans, dp[foo][i]);
    }
  }
  
  printf("%lld\n", ans);
  return;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}