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

const int N = 5e5 + 10;

int is[N];
int p[N], sz = 0;

void sieve() {
  is[0] = 0;
  is[1] = 1;
  is[2] = 2;
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
  debug("SIZE OF SIEVE = %d\n", sz);
}

ll qtd[N];
ll v[N], n;
map< vi, bool > ex, ex2;
ll rsp = 0;

void keepSolve(ll s) {
  rsp += (is[s] == s);
  for(int i = 0; i < sz; ++i) {
    if(p[sz] <= s) continue;
    rsp += qtd[p[sz] - s];
  }
}

int main() {
  sieve();
  scanf("%lld", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);

  sort(v, v + n);

  int mid = (n / 2);

  for(int i = 0; i < (1 << mid); ++i) {
    vi o;
    ll sum = 0;
    for(int j = 0; j < mid; ++j) if((i >> j) & 1) {
      o.pb(v[j]);
      sum += v[j];
    }
    if(ex.find(o) == ex.end()) {
      ex[o] = 1;
      qtd[sum]++;
      rsp += (is[sum] == sum);
    }
  }

  int q = 0;
  for(int i = mid + 1; i < n; ++i) v[q++] = v[i];


  for(int i = 0; i < q; ++i) {
    vi o;
    ll sum = 0;
    for(int j = 0; j < q; ++j) if((i >> j) & 1) {
      o.pb(v[j]);
      sum += v[j];
    }
    if(ex2.find(o) == ex2.end()) {
      ex2[o] = 1;
      keepSolve(sum);
    }
  }

  printf("%lld\n", rsp);




  return 0;
}