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

const int N = 101;

ll x, y, z, a, b, c;
ll pd[N][N][N];

inline void main2() {
  scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c);
  for(int i = 0; i <= x; ++i) for(int j = 0; j <= y; ++j) for(int k = 0; k <= z; ++k) {
    if(!i && !j && !k) pd[i][j][k] = 0;
    else {
      pd[i][j][k] = LINF;
      if(i) pd[i][j][k] = min(pd[i][j][k], pd[i - 1][j][k] + a);
      if(j) pd[i][j][k] = min(pd[i][j][k], pd[i][j - 1][k] + a);
      if(k) pd[i][j][k] = min(pd[i][j][k], pd[i][j][k - 1] + a);
      if(i && j) pd[i][j][k] = min(pd[i][j][k], pd[i - 1][j - 1][k] + b);
      if(i && k) pd[i][j][k] = min(pd[i][j][k], pd[i - 1][j][k - 1] + b);
      if(j && k) pd[i][j][k] = min(pd[i][j][k], pd[i][j - 1][k - 1] + b);
      if(i && j && k) pd[i][j][k] = min(pd[i][j][k], pd[i - 1][j - 1][k - 1] + c);
    }
  }
  printf("%lld\n", pd[x][y][z]);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}