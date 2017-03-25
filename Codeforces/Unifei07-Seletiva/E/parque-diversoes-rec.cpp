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
#define pi acos(-1.0)
#define eps 1e-6

const int N = 5020;

int n, m;
ll v[N][N];
bool memo[N][N];
double pd[N][N];

double func(int x, int y) {
  if(x == n - 1 && y == m - 1) return v[n - 1][n - 1];
  if(memo[x][y]) return pd[x][y];
  double ret = v[x][y];
  if(x < n - 1 && y < m - 1) ret += (func(x + 1, y) + func(x, y + 1)) * 0.5;
  else if(x < n - 1) ret += func(x + 1, y);
  else ret += func(x, y + 1);
  memo[x][y] = 1;
  return pd[x][y] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%lld", &v[i][j]);
  printf("%.10lf\n", func(0, 0));
  return 0;
}