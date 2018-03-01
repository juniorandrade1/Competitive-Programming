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

ll myceil(ll x, ll y) {
  return (x + y - 1) / y;
}

int ax, ay, bx, by; 

ll calc(ll sx, ll sy, ll gx, ll gy) {
  ll solX = max(myceil(ax, sx), myceil(bx, gx));
  ll solY = max(myceil(ay, sy), myceil(by, gy));
  return solX * solY;
}

int main() {
  freopen("giant.in", "r", stdin);
  freopen("giant.out", "w", stdout);
  scanf("%d %d %d %d", &ax, &ay, &bx, &by);
  int n; scanf("%d", &n);
  ll ans = LINF;
  while(n--) {
    int sx, sy, gx, gy; scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    ll sol = min(calc(sx, sy, gx, gy), calc(sy, sx, gy, gx));
    ll p; scanf("%lld", &p);
    ans = min(ans, sol * p);
  }
  printf("%lld\n", ans);
  return 0;
}