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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}


int main() {
  //arquivo();
  map<ii, ll> ok;
  ll a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  ok[ii(a, b)] = ok[ii(b, c)] = ok[ii(c, a)] = 1;
  ok[ii(b, a)] = ok[ii(c, b)] = ok[ii(a, c)] = 1;

  scanf("%lld %lld %lld", &a, &b, &c);
  int ans = 6;
  ans -= ok[ii(a, b)] * 2;
  ans -= ok[ii(b, c)] * 2;
  ans -= ok[ii(c, a)] * 2;
  printf("%d\n", ans);
  return 0;
}