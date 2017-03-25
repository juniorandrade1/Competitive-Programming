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
#define pi acos(-1.0)
#define eps 1e-6

const int N = 1010;

int n, k;
int v[N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  for(int i = 0; i + k - 1 < n; ++i) {
    int mx = -INF, mn = INF;
    for(int j = 0; j < k; ++j) {
      mx = max(mx, v[i + j]);
      mn = min(mn, v[i + j]);
    }
    if(i) printf(" ");
    printf("%d", mx - mn);
  }
  printf("\n");
  return 0;
}