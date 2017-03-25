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
double qtd;
double sum;

void back(int x, int y, double at = 0) {
  at += v[x][y];
  if(x == n - 1 && y == m - 1) {
    sum += at;
    qtd++;
    return;
  }
  if(x + 1 < n) back(x + 1, y, at);
  if(y + 1 < m) back(x, y + 1, at);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%lld", &v[i][j]);
  sum = 0;
  qtd = 0;
  back(0, 0);
  debug("%.10lf %.10lf\n", sum, qtd);
  printf("%.10lf\n", sum / qtd);
  return 0;
}