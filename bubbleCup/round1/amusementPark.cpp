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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1010;
const int K = 210;

int n, k;
int C[N][N];
ll  S[N][N];
ll dp[N][K];

void func(int node, int l, int r, int bL, int bR) {
  if(r < l) return;
  int x = (l + r) >> 1;
  int bst = x;
  for(int i = max(x, bL); i <= n; ++i) {
    if(dp[x][k] > S[x][i] + dp[i + 1][node - 1]) {
      dp[x][k] = S[x][i] + dp[i + 1][node - 1];
      bst = i;
    }
  }
  func(node, l, x - 1, bL, bst);
  func(node, x + 1, r, bst, bR);
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &C[i][j]), C[i][j] += C[i][j - 1] + C[i - 1][j] - C[i - 1][j - 1];
  for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) S[i][j] = C[j][j] - C[i - 1][j] - C[j][i - 1] + C[i - 1][i - 1];
  for(int i = 0; i <= n + 1; ++i) for(int j = 0; j <= k + 1; ++j) dp[i][j] = LINF;
  for(int i = 0; i <= k + 1; ++i) dp[n + 1][i] = 0;
  for(int i = 1; i <= k; ++i) func(i, 1, n, 1, n);
  printf("%lld\n", dp[1][k] / 2);
  return 0;
}