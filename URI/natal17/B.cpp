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

const int N = 1001;

inline void main2() {
  int x; scanf("%d", &x);
  int sol = 0;
  int foo = 0;
  while(x) {
    foo = (x & 1) ? foo + 1 : 0;
    x >>= 1;
    sol = max(sol, foo);
  }
  printf("%d\n", sol);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}