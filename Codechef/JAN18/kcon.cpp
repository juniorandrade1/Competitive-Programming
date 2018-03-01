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

const int N = 100000 + 10;

int n, k;
ll v[N];
ll ls[N], rs[N];

inline void main2() {
  scanf("%d %d", &n, &k);
  ll ans = -LINF;
  ll at = 0;
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", v + i);
    ans = max(ans, v[i]);
    ls[i] = rs[i] = v[i];
    at += v[i];
    if(at < 0) at = 0;
    else ans = max(ans, at);
  }
  if(ans < 0) {
    printf("%lld\n", ans);
    return;
  }
  for(int i = 2; i <= n; ++i) ls[i] += ls[i - 1];
  for(int i = n - 1; i >= 1; --i) rs[i] += rs[i + 1];
  ll bls = *max_element(ls + 1, ls + n + 1);
  ll brs = *max_element(rs + 1, rs + n + 1);
  ll tot = ls[n];
  if(k >= 2) {
    ans = max(ans, bls + brs + tot * (ll)(k - 2LL));
    ans = max(ans, bls + brs);
  }
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}