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

const int N = 20;

ll n;
ll pd[N][11][2];
bool memo[N][11][2];
ll pot[N];
int arr[N];

ll func(int pos, int lstNum, int ok) {
  if(pos == -1) return 0;
  if(memo[pos][lstNum][ok]) return pd[pos][lstNum][ok];
  ll ret = -LINF;
  for(int i = lstNum; i <= 9; ++i) {
    if(ok == 0 && i > arr[pos]) break;
    ret = max(ret, i * pot[pos] + func(pos - 1, i, ok | (arr[pos] > i)));
  }
  memo[pos][lstNum][ok] = 1;
  return pd[pos][lstNum][ok] = ret;
}

inline void solve(ll x) {
  int sz = 0;
  while(x) {
    if(sz == 0) pot[sz] = 1;
    else pot[sz] = pot[sz - 1] * 10LL;
    arr[sz++] = x % 10;
    x /= 10;
  }
  memset(memo, 0, sizeof memo);
  printf("%lld\n", func(sz - 1, 0, 0));
}

inline void main2(int _test) {
  scanf("%lld", &n);
  printf("Case #%d: ", _test);
  solve(n);
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}