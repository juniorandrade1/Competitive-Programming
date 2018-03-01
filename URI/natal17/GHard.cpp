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

const int N = 10010;
const int M = 11;
const int GAP = 100;

int pd[M][GAP];
int ax[M];

int func(int pos, int g) {
  if(pos == M) return abs(GAP - g) <= 5;
  if(pd[pos][g] != -1) return pd[pos][g];
  int ret = 0;
  if(ax[pos] == 0) ret = func(pos + 1, g);
  else ret = (func(pos + 1, g - pos) | func(pos + 1, g + pos));
  return pd[pos][g] = ret;
}

inline void main2() {
  int n; scanf("%d", &n);
  memset(ax, 0, sizeof ax);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ax[x] ^= 1;
  } 
  memset(pd, -1, sizeof pd);
  puts(func(0, GAP) ? "Feliz Natal!" : "Ho Ho Ho!");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}