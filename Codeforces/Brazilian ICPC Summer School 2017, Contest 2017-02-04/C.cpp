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

const int N = 1e6 + 10;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int n;
ll m[N], a[N], b[N];
ll aa[N], bb[N], mm[N];
set< ii > ord;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", m + i);
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    aa[a[i]] = i;
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", b + i);
    b[i] = aa[b[i]];
    bb[b[i]] = i;
  }

  for(int i = 1; i <= n; ++i) {
    debug("%lld %lld\n", aa[i], bb[i]);
  }

  ll sum = 0;



  return 0;
}