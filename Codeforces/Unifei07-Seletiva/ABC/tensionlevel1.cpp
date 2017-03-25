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
ll v[N];
int n, k;

ll func(int pos, int qtd) {
  if(pos == n) {
    if(qtd == 0) return 0;
    else return LINF;
  }
  if(qtd == 0) return LINF;
  if(dp[pos][qtd] != -1) return dp[pos][qtd];
  ll ret = LINF;
  ll s = 0;
  for(int i = pos; i < n; ++i) {
    s += v[i];
    ret = min(ret, func(i + 1, qtd - 1) + s * (ll)(i - pos + 1));
  }
  return dp[pos][qtd] = ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  memset(dp, -1, sizeof dp);
  sort(v, v + n);
  printf("%lld\n", func(0, k));
  return 0;
}
