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
#define PI acos(-1.0)
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 50;

ll pd[N];

int main() {
  printf("%d\n", N);
  ll lst = 0;
  pd[1] = 1;
  for(int i = 2; i <= N + 1; ++i) {
    pd[i] = pd[i - 1] + pd[i - 2];
    printf("%lld ", pd[i]);
  }
  printf("\n");
  return 0;
}