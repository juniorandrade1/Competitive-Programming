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

string all[] = {"UL", "UR", "R", "LR", "LL", "L"};

int dx[] = {-2, -2, 0, 2, 2, 0};
int dy[] = {-1, 1, 2, 1, -1, -2};

const int N = 202;

int n;
int xs, ys, xf, yf;
int dis[N][N];
int mov[N][N];

inline void bfs() {
  memset(dis, INF, sizeof dis);
  memset(mov, -1, sizeof mov);
  dis[xs][ys] = 0;
  queue< ii > q; q.push(ii(xs, ys));
  while(!q.empty()) {
    ii foo = q.front(); q.pop();
    int x = foo.F, y = foo.S;
    for(int i = 0; i < 6; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      if(dis[xx][yy] > dis[x][y] + 1) {
        dis[xx][yy] = dis[x][y] + 1;
        mov[xx][yy] = i;
        q.push(ii(xx, yy));
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  scanf("%d %d %d %d", &xs, &ys, &xf, &yf);
  bfs();
  int ans = dis[xf][yf];
  if(ans == INF) puts("Impossible");
  else {
    printf("%d\n", ans);
    vector< string > sol;
    while(xs != xf || ys != yf) {
      int ax = mov[xf][yf];
      sol.pb(all[ax]);
      xf += dx[(ax + 3) % 6];      
      yf += dy[(ax + 3) % 6];
    }
    reverse(sol.begin(), sol.end());
    for(int i = 0; i < sol.size(); ++i) {
      if(i) printf(" ");
      printf("%s", sol[i].c_str());
    }
  }
  return 0;
}