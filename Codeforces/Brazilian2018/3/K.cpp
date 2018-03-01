
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

const int N = 303;

int n, m;
int pd[N][N][N];
int v[N];

int func(int l, int r, int p) {
  if(l > r) return 0;
  if(l == r) return v[l] != p;
  if(pd[l][r][p] != -1) return pd[l][r][p];
  int ret = (r - l + 1);
  for(int i = l; i <= r; ++i) ret = min(ret, func(l, i - 1, v[i]) + func(i + 1, r, v[i]) + (v[i] != p));
  return pd[l][r][p] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  if(m == 1) {
    printf("0\n");
    return 0;
  }
  memset(pd, -1, sizeof pd);
  int sol = INF;
  for(int i = 1; i <= m; ++i) sol = min(sol, func(0, n - 1, i));
  printf("%d\n", sol);
  return 0;
}