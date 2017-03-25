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

const int N = 8010;

ll dp[N][2];
ll sumCum[N];

void func(int k, int l, int r, int loool, int rr){
  if(l>r) return;
  int m = (l + r) >> 1;
  int nxt = (k + 1) & 1;
  dp[m][k & 1] = LINF;
  int xd;
  for(ll i = max(loool,m);i<=rr;i++){
    ll cu = ((sumCum[i + 1] - sumCum[m])*(i - m + 1));
    if(dp[m][k & 1] > dp[i+1][nxt] + cu){
      dp[m][k & 1] = dp[i+1][nxt] + cu;
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
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i);
  sort(v + 1, v + n + 1);
  for(int i = 1; i <= n; ++i) sumCum[i] = sumCum[i - 1] + v[i];
  for(int i = 0; i <= n + 1; ++i) for(int j = 0; j < 2; ++j) dp[i][j] = LINF;
  dp[n][0] = 0;
  for(int i = 1; i <= k; ++i) {
    for(int j = 1; j <= n + 1; ++j) dp[j][i & 1] = LINF;
    dp[n][i & 1] = 0;
    func(i, 0, n - 1, 0, n - 1);
  }
  printf("%lld\n", dp[0][k & 1]);
  return 0;
}
