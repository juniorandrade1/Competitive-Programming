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

const int N = 50;


int main() {
  srand(time(NULL));
  printf("1\n");
  int k = rand() % N + 1;
  printf("%d %d", N, k);
  ll f = 1;
  printf("\n");
  for(int i = 0; i < N; ++i) {
    printf("%lld ", f);
    f <<= 1;
  }
  printf("\n1 10000000000000000000\n");
  return 0;
}