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

const int N = 123456;

int n;

inline void main2() {
  scanf("%d", &n);
  bool spc = false;
  for(int i = 1; i + 3 <= n; i += 2) {
    if(spc) printf(" ");
    printf("%d %d", i + 1, i);
    spc = true;
  }
  if(spc) printf(" ");
  if(n % 2 == 0) printf("%d %d\n", n, n - 1);
  else printf("%d %d %d\n", n - 1, n, n - 2);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}