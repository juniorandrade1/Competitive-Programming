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

const int N = 20;
const int M = 1010;

ll dp[N];
int n, x;
ll p[1 << N];

ll solve(int pos) {
  if(pos <= 0) return 1;
  if(dp[pos] != -1) return dp[pos];
  int ret = 0;
  if((x >> pos) & 1) {
    for(int j = pos - 1; j >= 0; --j) {
      if(!((x >> j) & 1)) ret = solve(j - 1);
    }
  }
  else ret = solve(pos - 1);
  return dp[pos] = ret;
}

ll calc(int _x) {
  memset(dp, -1, sizeof dp);
  x = _x;
  return solve(N - 1);
}

vector< int > g[N];

inline void main2() {
  scanf(" %s", s);
  scanf("%d", &x);
  n = strlen(s);
  
  return;
}

int main() {
  for(int i = 0; i < (1 << N); ++i) {
    p[i] = calc(i);
  }

  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}