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
const int M = 18;

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

inline void main2() {
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i), spt[i][0] = v[i];
  process();
  for(int i = 0; i <= n; ++i) for(int j = 0; j < 2; ++j) dp[j][i] = -LINF;
  dp[0][0] = 0;
  k++;
  for(int z = 1; z <= k; ++z) {
    int foo = (z & 1);
    int bck = ((z & 1) ^ 1);
    for(int i = 1; i <= n; ++i) {
      dp[foo][i] = -LINF;
      for(int j = 1; j <= i; ++j) {
        dp[foo][i] = max(dp[foo][i], dp[bck][j - 1] + (i - j + 1) * query(j, i));
      }
    }
  }
  printf("%lld\n", dp[k & 1][n]);
  return;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}