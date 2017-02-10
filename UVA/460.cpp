#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ull;
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
#define snd second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

int xi[2], yi[2], xf[2], yf[2];

int main() {
  int test; scanf("%d", &test);
  for(int z = 0; z < test; ++z) {
    if(z) puts("");
    for(int i = 0; i < 2; ++i) scanf("%d %d %d %d", xi + i, yi + i, xf + i, yf + i);
    int xl = max(xi[0], xi[1]);
    int yl = max(yi[0], yi[1]);
    int xr = min(xf[0], xf[1]);
    int yr = min(yf[0], yf[1]);
    if(xl < xr && yl < yr) printf("%d %d %d %d\n", xl, yl, xr, yr);
    else puts("No Overlap");
  }
  return 0;
}