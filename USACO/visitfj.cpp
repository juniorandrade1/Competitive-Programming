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

void arquivo() {
  freopen("visitfj.in", "r", stdin);
  freopen("visitfj.out", "w", stdout);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


const int N = 101;

struct est {
  ll x, y, m, w;
  est(){};
  est(ll _x, ll _y, ll _m, ll _w) {
    x = _x;
    y = _y;
    m = _m;
    w = _w;
  }
  bool operator < (est other) const {
    return w > other.w;
  }
};

ll v[N][N];
int n, t;
ll pd[N][N][3];

int main() {
  arquivo();
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
    scanf("%lld", &v[i][j]);
    pd[i][j][0] = pd[i][j][1] = pd[i][j][2] = LINF;
  }

  pd[1][0][1] = t;
  pd[0][1][1] = t;

  pq< est > q; 
  q.push(est(1, 0, 1, t));
  q.push(est(0, 1, 1, t));

  while(!q.empty()) {
    est foo = q.top(); q.pop();
    int x = foo.x, y = foo.y, m = foo.m;
    ll w = foo.w;
    if(pd[x][y][m] != w) continue;
    for(int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      ll cost = t;
      int mm = (m + 1) % 3;
      if(mm == 0) cost += v[xx][yy];
      if(pd[xx][yy][mm] > pd[x][y][m] + cost) {
        pd[xx][yy][mm] = pd[x][y][m] + cost;
        q.push(est(xx, yy, mm, pd[xx][yy][mm]));
      }
    }
  }

  ll ans = min(pd[n - 1][n - 1][0], min(pd[n - 1][n - 1][1], pd[n - 1][n - 1][2]));
  printf("%lld\n", ans);


  return 0;
}