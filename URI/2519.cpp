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

const int N = 1010;

int n, m;
int bit[N][N];

void add(int x, int y, int v) {
  x += 2;
  y += 2;
  for(int xx = x; xx < N; xx += LSONE(xx)) for(int yy = y; yy < N; yy += LSONE(yy)) bit[xx][yy] += v;
}

int query(int x, int y) {
  x += 2;
  y += 2;
  int q = 0;
  for(int xx = x; xx > 0; xx -= LSONE(xx)) for(int yy = y; yy > 0; yy -= LSONE(yy)) q += bit[xx][yy];
  return q;
}

int v[N][N];

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    memset(bit, 0, sizeof bit);
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        scanf("%d", &v[i][j]);
        add(i, j, v[i][j]);
      }
    }
    int q; scanf("%d", &q);
    while(q--) {
      int op, x1, y1, x2, y2;
      scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
      if(op == 0) {
        add(x1, y1, -1);
        add(x2, y2, 1);
      }
      else {
        //debug("%d %d %d %d\n", query(x2, y2), query(x1 - 1, y2), query(x2, y1 - 1),query(x1 - 1, y1 - 1));
        printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
      }
    }
  }
  return 0;
}