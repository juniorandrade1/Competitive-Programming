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
ll p[N], sz = 0;

void sieve() {
  is[0] = 0;
  is[1] = 1;
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      ll k = (ll)i * (ll)i;
      while(k < N) {
        is[k] = 1;
        k += i;
      }
    }
  }
  debug("SIZE OF SIEVE = %d\n", sz);
}

ll qtd[N];
ll v[N], n;
ll sum[N];
ll pd[52][N];
bool memo[52][N];
ll nxt[52];

ll func(int pos, int prime) {
  if(prime < 0) return 0;
  if(prime > sum[pos]) return 0;
  if(pos == n) return prime == 0;
  if(memo[pos][prime]) return pd[pos][prime];
  memo[pos][prime] = 1;
  ll ret = func(nxt[pos] + 1, prime);
  for(int i = pos; i <= nxt[pos]; ++i) {
    ret += func(nxt[pos] + 1, prime - (i - pos + 1) * v[pos]);
  }
  return pd[pos][prime] = ret;
}

int main() {
  sieve();
  scanf("%lld", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  for(int i = n - 1; i >= 0; --i) sum[i] = sum[i + 1] + v[i];
  for(int i = 0; i < n; ++i) {
    for(int j = i; j < n; ++j) {
      if(v[i] != v[j]) break;
      nxt[i] = j;
    }
  }
  ll ans = 0;
  for(int i = 0; i < sz; ++i) ans += func(0, p[i]);
  printf("%lld\n", ans);  
  return 0;
}