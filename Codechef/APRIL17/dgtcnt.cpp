
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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

ll a[20];
ll d[20];
ll l, r;

ll pd[20][(1 << 11)][2];
int num[20];

ll func(int pos, int mask, int ok) {
  if(pos < 0) return __builtin_popcount(mask) == 10;
  if(pd[pos][mask][ok] != -1) return pd[pos][mask][ok];
  ll ret = 0;
  for(int i = 0; i < 10; ++i) {
    if(ok == 0 && num[pos] < i) break;
    ret += func(pos - 1, mask | (1 << i), ok | (i < num[pos]));
  }
  return pd[pos][mask][ok] = ret;
}

ll solve(ll x) {
  ll xx = x;
  int sz = 0;
  while(xx) {
    num[sz++] = (xx % 10);
    xx /= 10;
  }
  if(sz < 10) return 0;
  memset(pd, -1, sizeof pd);
  ll sum = 0;
  for(int i = 1; i < sz - 1; ++i) for(int j = 1; j < 10; ++j) sum += func(i - 2, (1 << j), 1);
  for(int i = num[sz - 1]; i > 0; --i) sum += func(sz - 2, (1 << i), i < num[sz - 1]);
  return sum;
}

inline void smartIfAllZero() {
  printf("%lld\n", solve(r) - solve(l - 1));
}

inline void stupid() {
  ll sum = 0;
  for(ll i = l; i <= r; ++i) {
    ll x = i;
    while(x) {
      d[x % 10]++;
      x /= 10;
    }
    int q = 0;
    for(int j = 0; j < 10; ++j) {
      q += (a[j] == d[j]);
      d[j] = 0;
    }
    sum += (q == 0);
  }
  printf("%lld\n", sum);
}

inline void main2() {
  scanf("%lld %lld", &l, &r);
  ll sum = 0;
  for(int i = 0; i < 10; ++i) {
    scanf("%lld", a + i);
    sum += a[i];
  }
  if(sum == 0) {
    smartIfAllZero();
  }
  else {
    stupid();
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}