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

inline ll countTwo(ll x, ll y, ll z) {
  ll sol = 0;
  int u = min(x, z - y);
  sol += u;
  x -= u;
  z -= u;
  int da = x / 2;
  int db = x - da;
  sol += x;
  z -= db;
  y -= da;
  sol += min(y, z);
  return sol;
}

ll x, y, z, a, b, c;

inline ll goO(int i) {
  int xx = x - i, yy = y - i, zz = z - i;
  return (xx + yy + zz) * a + i * c;
}

inline ll goT(int i) {
  int xx = x - i, yy = y - i, zz = z - i;
  ll qt = countTwo(xx, yy, zz);
  return (xx + yy + zz - 2LL * qt) * a + qt * b + i * c;
}

inline void main2() {
  scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c);
  if(x > y) swap(x, y);
  if(x > z) swap(x, z);
  if(y > z) swap(y, z);
  ll mz = x;
  ll ans = a * (x + y + z);
  ans = min(ans, goO(0));
  ans = min(ans, goO(mz));
  for(int i = 0; i <= mz; ++i) ans = min(ans, goT(i));
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
