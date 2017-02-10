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



int main() {
  int n; scanf("%d", &n);
  vi sol;
  if(n % 2 == 1) {
    n -= 3;
    sol.pb(3);
  }
  while(n) {
    sol.pb(2);
    n-=2;
  }
  printf("%d\n", (int)sol.size());
  sort(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i) {
    printf("%lld ", sol[i]);
  }
  printf("\n");
  return 0;
}