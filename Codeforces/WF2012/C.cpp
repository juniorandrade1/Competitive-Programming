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

const int N = 20;

int n, m;
int g[N][N];

int dpSource[1 << N][N], dpSink[1 << N][N];

int calculateSource(int mask, int pos) {
  if(mask == 0) dpSource[mask][pos] = g[pos][0];
  if(dpSource[mask][pos] != -1) return dpSource[mask][pos];
  int ret = INF;
  for(int j = 0; j < n; ++j) if((mask >> j) & 1) ret = min(ret, g[pos][j] + calculateSource(mask ^ (1 << j), j));
  return dpSource[mask][pos] = ret;
}

int calculateSink(int mask, int pos) {
  if(mask == 0) dpSink[mask][pos] = g[pos][n - 1];
  if(dpSink[mask][pos] != -1) return dpSink[mask][pos];
  int ret = INF;
  for(int j = 0; j < n; ++j) if((mask >> j) & 1) ret = min(ret, g[pos][j] + calculateSink(mask ^ (1 << j), j));
  return dpSink[mask][pos] = ret;
}

inline void main2(int _test) {
  for(int i = 0; i < n; ++i) for(int j = 0; j < N; ++j) g[i][j] = (i == j) ? 0 : INF;
  for(int i = 0; i < m; ++i) {
    int x, y, w; scanf("%d %d %d", &x, &y, &w);
    g[x][y] = min(g[x][y], w);
    g[y][x] = min(g[y][x], w);
  }
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  int h = (n - 2);
  memset(dpSource, -1, sizeof dpSource);
  memset(dpSink, -1, sizeof dpSink);
  int ans = INF;
  if(n == 3) {
    ans = (g[0][1] + g[1][2]) * 2;
  }
  if(h % 2 == 0) {
    for(int i = 0; i < (1 << n); ++i) {
      if(((i >> 0) & 1) || ((i >> n - 1) & 1)) continue;
      if(__builtin_popcount(i) == h / 2) {
        int fstBit = (1 << (n - 1));
        int lstBit = (1 << 0);
        int nMask = (((1 << n) - 1) ^ i ^ fstBit ^ lstBit);
        int minGo = INF;
        int minReturn = INF;
        for(int j = 0; j < n; ++j) if((i >> j) & 1) {
          for(int k = 0; k < n; ++k) if((nMask >> k) & 1) {
            int sumGo = calculateSource(i ^ (1 << j), j) + g[j][k] + calculateSink(nMask ^ (1 << k), k);
            int sumReturn = calculateSink(i ^ (1 << j), j) + g[j][k] + calculateSource(nMask ^ (1 << k), k);
            minGo = min(minGo, sumGo);
            minReturn = min(minReturn, sumReturn);
          }
        }
        ans = min(ans, minGo + minReturn);
      }
    }
  }
  else {
    for(int i = 0; i < (1 << n); ++i) {
      if(((i >> 0) & 1) || ((i >> n - 1) & 1)) continue;
      if(__builtin_popcount(i) == h / 2) {
        int fstBit = (1 << (n - 1));
        int lstBit = (1 << 0);
        int nFstMask = (((1 << n) - 1) ^ i ^ fstBit ^ lstBit);
        int minGo = INF;
        int minReturn = INF;
        for(int j = 0; j < n; ++j) if((i >> j) & 1) {
          for(int l = 0; l < n; ++l) if((nFstMask >> l) & 1) {
            int nMask = (nFstMask ^ (1 << l));
            for(int k = 0; k < n; ++k) if((nMask >> k) & 1) {
              int sumGo = calculateSource(i ^ (1 << j), j) + g[j][l] + g[l][k] + calculateSink(nMask ^ (1 << k), k);
              int sumReturn = calculateSink(i ^ (1 << j), j) + g[j][l] + g[l][k] + calculateSource(nMask ^ (1 << k), k);
              minGo = min(minGo, sumGo);
              minReturn = min(minReturn, sumReturn);
            }
          }
        }
        ans = min(ans, minGo + minReturn);
      }
    }
  }
  printf("Case %d: %d\n", _test, ans);
}


int main() {
  int test = 1;
  while(scanf("%d %d", &n, &m) != EOF) main2(test++);
  return 0;
}