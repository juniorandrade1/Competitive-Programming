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
int main() {
  int n; cin >> n;
  int s = ((n * (n + 1)) / 2LL);
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < i && n - j >= i; ++j) {
      int q = ((n - j) / i) - 1;
      s -= q;
    }
  }
  printf("%d\n", s);
  return 0;
}