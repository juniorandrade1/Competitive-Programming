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

const ll md = (ll)(1000000007);

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

const int N = 1000001;

int n, m;
ll v[N];
ll dpMax[N];
ll dpCnt[N];

int main() {
  while(scanf("%d %d", &n, &m) != EOF && n && m) {
    dpCnt[0] = 1;
    for(int i = 0; i < n; ++i) {
      scanf("%lld", v + i);
      for(int j = m; j >= v[i]; --j) {
        if(dpMax[j] < dpMax[j - v[i]] + 1) {
          dpMax[j] = dpMax[j - v[i]] + 1;
          dpCnt[j] = dpCnt[j - v[i]];
        }
        else if(dpMax[j] == dpMax[j - v[i]] + 1) {
          dpCnt[j] = addMod(dpCnt[j], dpCnt[j - v[i]]);
        }
      }
    }
    ll maxTam = 0;
    for(int i = 0; i <= m; ++i) maxTam = max(maxTam, dpMax[i]);
    ll ans = 0;
    for(int i = 0; i <= m; ++i) if(maxTam == dpMax[i]) ans = addMod(ans, dpCnt[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
