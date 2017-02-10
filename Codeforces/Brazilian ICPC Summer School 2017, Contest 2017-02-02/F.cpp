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

const int N = 2e4;

void arquivo() {
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
}

int pd[N];

int func(int x) {
  if(pd[x] != -1) return pd[x];
  if(x == 0) return 0;
  map<int, int> s;
  for(int i = 1; i * i <= x; ++i) {
    s[func(x - i)] = 1;
  }
  int q = 0;
  while(s[q]) q++;
  return pd[x] = q;
}

int main() {
  arquivo();
  memset(pd, -1, sizeof pd);
  ll n; scanf("%lld", &n);
  if(n < N) {
    if(func(n) == 0) puts("LOSE");
    else puts("WIN");
  }
  else {
    ll f = 12;
    while(f < n) f += 1 + (ll)sqrt(f + 1 + sqrt(f));
    if(f == n) puts("LOSE");
    else puts("WIN");
  }
  return 0;
}