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

const int N = 10000001;

int p[N], sz = 0;
int is[N];

void sieve() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
}

vi factorize(ll x) {
  vi ax;
  for(int i = 0; i < sz; ++i) while(x % p[i] == 0) ax.pb(p[i]), x /= p[i];
  if(x > 1) ax.pb(x);
  sort(ax.begin(), ax.end());
  return ax;
}


inline ll calc(ll x) {
  if(x == 1) return 1;

  vi ft = factorize(x);
  ll ans = x;
  for(int i = 0; i < ft.size(); ++i) {
    x /= ft[i];
    ans += x;
  }
  return ans;
}

int main() {
  sieve();

  int n;
  scanf("%d", &n);
  ull ans = 0;
  for(int i = 0; i < n; ++i) {
    ull x; scanf("%lld", &x);
    ans += (ull)calc(x);
  }
  printf("%llu\n", ans);
  return 0;
}