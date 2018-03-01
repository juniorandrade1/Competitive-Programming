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

const int N = 1001;

int n;
ll v[N][5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) for(int j = 0; j < 5; ++j) scanf("%lld", &v[i][j]);
  if(n > 100) puts("0");
  else {
    vi sol;
    for(int a = 0; a < n; ++a) {
      bool ok = true;
      for(int b = 0; b < n; ++b) {
        for(int c = 0; c < n; ++c) {
          if(a == b || a == c || b == c) continue;
          ll dot = 0;
          for(int k = 0; k < 5; ++k) dot += (v[b][k] - v[a][k]) * (v[c][k] - v[a][k]);
          if(dot > 0) ok = false;
        }
      }
      if(ok) sol.pb(a);
    }
    printf("%d\n", (int)sol.size());
    for(int i = 0; i < (int)sol.size(); ++i) printf("%lld\n", sol[i] + 1);
  }
  return 0;
}