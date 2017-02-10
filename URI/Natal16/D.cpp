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

const int N = 5010;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
char s[N][N];
int group[N][N];
int sz[N * N];
int minDistGroup[N];
int cntGroup;

void bfs(int sx, int sy) {
  queue<ii>q; q.push(ii(sx, sy));
  group[sx][sy] = cntGroup;
  while(!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    for(int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx >= n || xx < 0 || yy >= m || yy < 0) continue;
      if(group[xx][yy] == 0 && s[xx][yy] == '.') {
        group[xx][yy] = cntGroup;
        sz[cntGroup]++;
        q.push(mp(xx, yy));
      }
    }
  }
  cntGroup++;
}

int dis[N][N];

inline void main2(int test) {
  if(test != 1) printf("\n");
  cntGroup = 1;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      scanf(" %c", &s[i][j]);
      group[i][j] = 0;
      sz[i * m + j] = 1;
      dis[i][j] = INF;
      minDistGroup[i * m + j] = INF;
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(group[i][j] == 0 && s[i][j] == '.') {
        bfs(i, j);
      }
    }
  }
  int idCentral = 1;
  int sizeCentral = sz[idCentral];
  for(int i = 1; i < cntGroup; ++i) {
    if(sizeCentral < sz[i]) {
      idCentral = i;
      sizeCentral = sz[i];
    }
  }
  for(int i = 1; i < cntGroup; ++i) {
    if(i == idCentral) continue;
    assert(sizeCentral != sz[i]);
  }
  queue<ii>q;
  for(int i = 0; i < n && q.empty(); ++i) {
    for(int j = 0; j < m && q.empty(); ++j) {
      if(s[i][j] == '.' && group[i][j] == idCentral) {
        q.push(ii(i, j));
        dis[i][j] = 0;
      }
    }
  }

  while(!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    minDistGroup[group[x][y]] = min(minDistGroup[group[x][y]], dis[x][y]);
    for(int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx >= n || xx < 0 || yy >= m || yy < 0) continue;
      if(s[xx][yy] == '#') continue;
      int cost = 1;
      if(s[xx][yy] == '.' && s[x][y] == '.') cost = 0;
      if(dis[xx][yy] > dis[x][y] + cost) {
        dis[xx][yy] = dis[x][y] + cost;
        q.push(mp(xx, yy));
      }
    }
  }

  ll minDistance = 0;
  ll sum = 0;
  printf("Instance #%02d:\n", test);
  for(int i = 1; i < cntGroup; ++i) {
    if(i == idCentral) continue;
    if(minDistGroup[i] == INF) {
      puts("Network Error");
      return;    
    }
    minDistGroup[i]--;
    sum += (ll)(minDistGroup[i]);
    minDistance += (ll)sz[i] * (minDistGroup[i]);
  }
  printf("%d %lld %lld\n", sizeCentral, sum, minDistance);
}

int main() {
  int test = 1;
  while(scanf("%d %d", &n, &m) != EOF) main2(test++);
  return 0;
}