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
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  a %= b;
  for(int i = 1; i <= 1000000; ++i) {
    a *= 10;  
    int fit = -1;
    for(int j = 9; j >= 0; --j) {
      if(b * j <= a) {
        fit = j;
        break;
      }
    }
    a -= b * fit;
    if(fit == c) {
      printf("%d\n", i);
      exit(0);
    }
  }
  printf("-1\n");
  return 0;
}