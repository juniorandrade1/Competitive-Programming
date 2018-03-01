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

const int N = 8;

int dx[] = {-2, -2, 1, 1, 2, 2, -1, -1};
int dy[] = {-1, 1, -2, 2, -1, 1, -2, 2};

char s[N][N];
int dis[N][N];


inline int bfs(int xs, int ys, int xf, int yf) {
  queue<ii>q; 
  memset(dis, INF, sizeof dis);
  dis[xs][ys] = 0;
  q.push(mp(xs, ys));
  while(!q.empty()) {
    ii foo = q.front(); q.pop();
    int x = foo.F, y = foo.S;
    //printf("%d %d\n", x, y);
    for(int i = 0; i < 8; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
      if(s[xx][yy] == 'X') continue;
      if(dis[xx][yy] > dis[x][y] + 1) {
        dis[xx][yy] = dis[x][y] + 1;
        q.push(mp(xx, yy));
      }
    }
  }
  return dis[xf][yf];
}

int main() {
  int xs, xf, ys, yf;
  for(int i = 0; i < N; ++i) {
    scanf(" %s", s[i]);
    for(int j = 0; j < N; ++j) {
      if(s[i][j] == 'I') {
        xs = i;
        ys = j;
      }
      else if(s[i][j] == 'F') {
        xf = i;
        yf = j;
      }
    }
  }
  int sol = bfs(xs, ys, xf, yf);
  if(sol == INF) puts("Impossivel ir de I a F");
  else printf("Numero minino de movimentos: %d\n", sol);
  return 0;
}