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

const int N = 30;

int n;
ll m;
ll v[N];

inline bool checkOverflow(ll a, ll b) {
  if(a) return b > m / a;
  return a > m / b;
}

vi fst;

int main() {
  scanf("%d %lld", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  ll ans = 0;
  int mid = (n / 2);
  for(int i = 1; i < (1 << mid); ++i) {
    ll mt = 1; 
    for(int j = 0; j < mid; ++j) {
      if((i >> j) & 1) {
        if(checkOverflow(mt, v[j])) {
          mt = m + 1;
          break;
        }
        else mt *= v[j];
      }
    }
    if(mt > m) continue;
    ans++;
    fst.pb(mt);
  }
  sort(fst.begin(), fst.end());
  int cnt = 0;
  for(int i = mid; i < n; ++i) v[cnt++] = v[i];
  for(int i = 1; i < (1 << cnt); ++i) {
    ll mt = 1;
    for(int j = 0; j < cnt; ++j) if((i >> j) & 1) {
      if(checkOverflow(mt, v[j])) {
        mt = m + 1;
        break;
      }
      mt *= v[j];
    }
    if(mt > m) continue;
    ans++;
    ll need = m / mt;
    ans += (upper_bound(fst.begin(), fst.end(), need) - fst.begin());
  }
  printf("%lld\n", ans);
  return 0;
}
