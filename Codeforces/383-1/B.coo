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

int n, z;
int q[N];

int main() {
  scanf("%d %d", &n, &z);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    q[x]++;
  }
  ll foo = 0;
  for(int i = 0; i < 100001; ++i) {
    ll oth = z ^ i;
    if(oth > 100000) continue;
    foo += (ll)q[i] * (ll)q[oth];
    q[i] = q[oth] = 0;
  }
  printf("%lld\n", foo);
  return 0;
}