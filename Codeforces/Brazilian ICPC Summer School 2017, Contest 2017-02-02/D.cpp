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

void arquivo() {
  freopen("exchange.in", "r", stdin);
  freopen("exchange.out", "w", stdout);
}
 

int a[N];
ll pd[2][1 << 10][1 << 10][2];

ll func(int pos, int m1, int m2, int ok) {
  if(pos == -1) return 1;
  if(pd[pos & 1][m1][m2][ok] != -1) return pd[pos & 1][m1][m2][ok];
  ll ret = 0;
  for(int i = 0; i < 10; ++i) {
    if(ok == 0 && i > a[pos]) break;
    int s = ((m1 >> i) & 1) + ((m2 >> i) & 1);
    if(s == 2) continue;
    
    if(s == 0) {
      int nm1 = (m1 | (1 << i));
      ret += func(pos - 1, nm1, m2, ok | (i < a[pos]));
    }
    else {
      int nm2 = (m2 | (1 << i));
      ret += func(pos - 1, m1, nm2, ok | (i < a[pos]));
    }
  }
  return pd[pos & 1][m1][m2][ok] = ret;
}

ll calc(ll x) {
  if(x == 0) return 0;
  int q = 0;
  while(x) {
    a[q++] = x % 10;
    x /= 10;
  }
  ll ans = 0;
  memset(pd, -1, sizeof pd);

  for(int i = 0; i <= q - 2; ++i) for(int j = 1; j < 10; ++j) {
    memset(pd[i & 1], -1, sizeof pd[i & 1]);
    ans += func(i - 1, (1 << j), 0, 1);
  }

  memset(pd[(q - 1) & 1], -1, sizeof pd[(q - 1) & 1]);
  for(int j = 1; j <= a[q - 1]; ++j) ans += func(q - 2, (1 << j), 0, j < a[q - 1]);
  return ans;
}

int main() {
  //arquivo();
  ll l, r; scanf("%lld %lld", &l, &r);
  printf("%lld\n", calc(r) - calc(l - 1));
  return 0;
}