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

const int N = 110;
const int GAP = N * 110;

int n;
int a[N];
int pd[N][N * 220];

int func(int pos, int at) {
  if(pos == n) return abs(GAP - at);
  if(pd[pos][at] != -1) return pd[pos][at];
  int l = abs(GAP - at);
  return pd[pos][at] = min(max(l, func(pos + 1, at + a[pos])), max(l, func(pos + 1, at - a[pos])));
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(0, GAP));  
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}