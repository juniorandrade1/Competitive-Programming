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
double qa[N][N];
double qb[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%lld", &v[i][j]);
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    if(i == 0 && j == 0) qa[i][j] = 1.0;
    else if(i && j) qa[i][j] = qa[i - 1][j] + qa[i][j - 1];
    else if(i) qa[i][j] = qa[i - 1][j];
    else qa[i][j] = qa[i][j - 1];
  }
  for(int i = n - 1; i >= 0; --i) for(int j = m - 1; j >= 0; --j) {
    if(i == n - 1 && j == m - 1) qb[i][j] = 1.0;
    else if(i < n - 1 && j < m -  1) qb[i][j] = qb[i + 1][j] + qb[i][j + 1];
    else if(i < n - 1) qb[i][j] = qb[i + 1][j];
    else qb[i][j] = qb[i][j + 1];
  }
  double ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      ans += (qa[i][j] * qb[i][j] * v[i][j]) / qa[n - 1][m - 1];
    }
  }
  debug("%.10lf %.2lf\n", ans, qa[n - 1][m - 1]);
  printf("%.10lf\n", ans);
  return 0;
}