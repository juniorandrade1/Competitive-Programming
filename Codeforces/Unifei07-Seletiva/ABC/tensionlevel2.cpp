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
#define pi acos(-1.0)
#define eps 1e-6

const int N = 510;

ll dp[N][N];
ll sumCum[N];

void func(int k, int l, int r, int loool, int rr){
  if(l>r) return;
  int m = (l + r) >> 1;
  dp[m][k] = LINF;
  int xd;
  for(ll i = max(m, loool); i <= rr; i++){
    ll cu = ((sumCum[i + 1] - sumCum[m])*(ll)(i - m));
    if(dp[m][k] > dp[i + 1][k - 1] + cu){
      dp[m][k] = dp[i + 1][k - 1] + cu;
      xd = i;
    }
  }
  func(k, l, m - 1, loool, xd);
  func(k , m + 1, r, xd, rr);
}

ll v[N];
int n, k;

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  sumCum[0] = 0;
  for(int i = 1; i <= n; i++) sumCum[i] = (sumCum[i - 1] + v[i - 1]);
  for(int i = 0; i <= n + 1; ++i) for(int j = 0; j <= k + 1; ++j) dp[i][j] = LINF;
  for(int i = 0; i <= k + 1; ++i) dp[n][i] = 0;
  for(int i = 1; i <= k; ++i) func(i, 0, n - 1, 0, n - 1);
  printf("%lld\n", dp[0][k] + sumCum[n]);
  return 0;
}
