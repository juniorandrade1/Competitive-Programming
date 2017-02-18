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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void arquivo() {
  freopen("countcross.in", "r", stdin);
  freopen("countcross.out", "w", stdout);
}

const int N = 110;

int n, k, r;
map< pair<ii, ii>, bool > nop;
int comp[N][N];
int marc[N][N];
ii cows[N * N];

ll sum = 0;

inline ll bfs(int sx, int sy) {
  ll foo = 0;
  queue<ii>q; q.push(mp(sx, sy));
  comp[sx][sy] = 1;
  while(!q.empty()) {
    ii oth = q.front(); q.pop();
    int x = oth.F, y = oth.S;
    foo += marc[x][y];
    for(int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      if(nop[mp(ii(x, y), ii(xx, yy))]) continue;
      if(comp[xx][yy] == -1) {
        comp[xx][yy] = 1;
        q.push(mp(xx, yy));
      }
    }
  }
  ll sol = foo * sum;
  sum += foo;
  return sol;
}


int main() {
  arquivo();
  scanf("%d %d %d", &n, &k, &r);
  for(int i = 0; i < r; ++i) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    nop[mp(ii(a, b), ii(c, d))] = nop[mp(ii(c, d), ii(a, b))] = 1;
  }
  memset(comp, -1, sizeof comp);
  ll ans = 0;
  for(int i = 0; i < k; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    cows[i] = ii(x, y);
    marc[x][y]++;
  }
  for(int i = 0; i < k; ++i) {
    int x = cows[i].F, y = cows[i].S;
    if(comp[x][y] == -1) ans += bfs(x, y);
  }
  printf("%lld\n", ans);
  return 0;
}