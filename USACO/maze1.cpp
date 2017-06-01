/*
 ID: juninho4
 PROG: maze1
 LANG: C++
 */

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

const int N = 202;

char s[N][N];
int dis[N][N];
int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

char buf[N];

int main() {

  FILE *fin, *fout;
  fin = fopen("maze1.in", "r");
  fout = fopen("maze1.out", "w");


  fscanf(fin, "%d %d", &m, &n);
  n = 2 * n + 1;
  m = 2 * m + 1;

  fgets(s[0], sizeof s[0], fin);
  for(int i = 0; i < n; ++i) fgets(s[i], sizeof s[i], fin);

  queue< ii > q;
  memset(dis, INF, sizeof dis);
  for(int i = 0; i < n; ++i) {
    if(s[i][0] == ' ' && dis[i][0] == INF) {
      q.push(ii(i, 0));
      dis[i][0] = 0;
    }
    if(s[i][m - 1] == ' ' && dis[i][m - 1] == INF) {
      q.push(ii(i, m - 1));
      dis[i][m - 1] = 0;
    }
  }

  for(int i = 0; i < m; ++i) {
    if(s[0][i] == ' ' && dis[0][i] == INF) {
      q.push(ii(0, i));
      dis[0][i] = 0;
    }
    if(s[n - 1][i] == ' ' && dis[n - 1][i] == INF) {
      q.push(ii(n - 1, i));
      dis[n - 1][i] = 0;
    }
  }

  int ans = 0;
  while(!q.empty()) {
    ii foo = q.front(); q.pop();
    int x = foo.F, y = foo.S;
    for(int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if(s[xx][yy] != ' ') continue;
      if(dis[xx][yy] > dis[x][y] + 1) {
        dis[xx][yy] = dis[x][y] + 1;
        q.push(mp(xx, yy));
        ans = max(ans, dis[xx][yy]);
      }
    }
  }
  fprintf(fout, "%d\n", (ans + 1) / 2);
  return 0;
}