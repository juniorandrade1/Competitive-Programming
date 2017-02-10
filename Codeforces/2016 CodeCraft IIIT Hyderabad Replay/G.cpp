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
#define eps 1e-6

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 70;

ll l, r, a, b;
ll pd[N][2][2][2][2];

ll calc(ll bX, ll bY, ll bZ, ll pot) {
  ll xy = (bX ^ bY);
  ll yz = (bY & bZ);
  ll zx = (bZ ^ bX); 
  return xy * pot + yz * pot + zx * pot;
}

ll func(int pos, int okL, int okR, int okA, int okB) {
  if(pos == -1) return 0;
  if(pd[pos][okL][okR][okA][okB] != -1) return pd[pos][okL][okR][okA][okB];
  ll ret = 0;
  ll pot = (1LL << pos);

  int bL = ((l >> pos) & 1);
  int bR = ((r >> pos) & 1);
  int bA = ((a >> pos) & 1);
  int bB = ((b >> pos) & 1);

  for(int x = 0; x < 2; ++x) {
    if(!okL && bL == 1 && x == 0) continue;
    if(!okR && bR == 0 && x == 1) continue;
    for(int y = 0; y < 2; ++y) {
      if(!okA && bA == 0 && y == 1) continue;
      for(int z = 0; z < 2; ++z) {
        if(!okB && bB == 0 && z == 1) continue;
        int newL = ((bL == 0) && (x == 1));
        int newR = ((bR == 1) && (x == 0));
        int newA = ((bA == 1) && (y == 0));
        int newB = ((bB == 1) && (z == 0));
        ret = max(ret, calc(x, y, z, pot) + func(pos - 1, okL | newL, okR | newR, okA | newA, okB | newB));
      }
    }
  }
  return pd[pos][okL][okR][okA][okB] = ret;
}

inline void main2() {
  scanf("%lld %lld %lld %lld", &l, &r, &a, &b);
  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(63, 0, 0, 0, 0));
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}