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

const int N = 1e5 + 10;

int n;
ll v[N];
ll dp[N][2];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i);
  ll ans = 0;
  for(int i = 1; i < n; ++i) {
    ll s = abs(v[i] - v[i + 1]);
    dp[i][0] = max(s, s + dp[i - 1][1]);
    dp[i][1] = max(-s, -s + dp[i - 1][0]);
    ans = max(ans, dp[i][0]);
    ans = max(ans, dp[i][1]);
  }
  printf("%lld\n", ans);4
  return 0;
}