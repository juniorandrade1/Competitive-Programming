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

const int N = 1e5 + 10;

int n, k;
ll v[N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  ll d = 0;
  for(int i = 0; i < n; ++i) {
    d += (v[i] + k - 1) / k;
  }
  printf("%lld\n", (d + 1) / 2);
  return 0;
}