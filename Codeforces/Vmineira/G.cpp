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

const int N = 20;

ll pd[N][N][N];
ll g[N][N];
int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    int w; scanf("%d", &w);
    g[x - 1][y - 1] = w;
    g[y - 1][x - 1] = w;
  }
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) pd[i][j][1] = g[i][j];
  for(int z = 2; z <= k; ++z) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        for(int l = 0; l < n; ++l) {
          pd[i][j][z] += (pd[i][l][z - 1] * pd[l][j][1]);
        }
      }
    }
  }

  int t; scanf("%d", &t);
  while(t--) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    ll sum = 0;
    for(int i = 1; i <= k; ++i) sum += pd[a][b][i];
    printf("%lld\n", sum);
  }
  return 0;
}