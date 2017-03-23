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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int N = 50;

int r, n, m, maximum;
char mapa[N][N];

struct field {
  ii pos1;
  vii pos2;
  field();
  field(ii _pos1, vii _pos2) {
    pos1 = _pos1;
    pos2 = _pos2;
  }
  bool operator < (field other) const {
    if(pos1 != other.pos1) return pos1 < other.pos1;
    return pos2 < other.pos2;
  }
};

map< field, int > dis;

bool finishField(field f) {
  return mapa[f.pos1.F][f.pos1.S] == 'X';
}

int bfs(field start) {
  queue< field > q; q.push(start); dis[start] = 0;
  while(!q.empty()) {
    field foo = q.front(); q.pop();
    if(finishField(foo)) return dis[foo];
    if(dis[foo] == maximum) continue;
    int wwwwwww = dis[foo];
    for(int i = 0; i < foo.pos2.size(); ++i) {
      int x = foo.pos2[i].F;
      int y = foo.pos2[i].S;
      for(int k = 0; k < 4; ++k) {
        int z = 1;
        while(1) {
          int xx = x + dx[k] * z, yy = y + dy[k] * z;
          if(xx < 0 || yy < 0 || xx >= n || yy >= m) break;
          if(ii(xx, yy) == foo.pos1) break;
          int ok = 0;
          for(int j = 0; j < foo.pos2.size() && !ok; ++j) if(ii(xx, yy) == foo.pos2[j]) ok = 1;
          if(ok) break;
          if(mapa[xx][yy] == '.' || mapa[xx][yy] == 'X') {
            z++;
          }
          else break;
        }
        if(z == 1) continue;
        int xx = x  + dx[k] * (z - 1), yy = y + dy[k] * (z - 1);
        field cp = foo;
        cp.pos2[i] = ii(xx, yy);
        sort(cp.pos2.begin(), cp.pos2.end());
        if(dis.find(cp) == dis.end()) {
          dis[cp] = dis[foo] + 1;
          q.push(cp);
        }
      }
    }


    int x = foo.pos1.F;
    int y = foo.pos1.S;
    for(int k = 0; k < 4; ++k) {
      int z = 1;
      while(1) {
        int xx = x + dx[k] * z, yy = y + dy[k] * z;
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) break;
        if(ii(xx, yy) == foo.pos1) break;
        int ok = 0;
        for(int j = 0; j < foo.pos2.size() && !ok; ++j) if(ii(xx, yy) == foo.pos2[j]) ok = 1;
        if(ok) break;
        if(mapa[xx][yy] == '.' || mapa[xx][yy] == 'X') {
          z++;
        }
        else break;
      }
      if(z == 1) continue;
      int xx = x  + dx[k] * (z - 1), yy = y + dy[k] * (z - 1);
      field cp = foo;
      cp.pos1 = ii(xx, yy);
      if(dis.find(cp) == dis.end()) {
        dis[cp] = dis[foo] + 1;
        q.push(cp);
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d %d %d", &r, &m, &n, &maximum);
  ii pos1;
  vii pos2;
  for(int i = 0; i < n; ++i) {
    scanf(" %s", mapa[i]);
    for(int j = 0; j < m; ++j) {
      if(mapa[i][j] >= '2' && mapa[i][j] <= '5') mapa[i][j] = '2';
      if(mapa[i][j] == '1') {
        pos1 = ii(i, j);
        mapa[i][j] = '.';
      }
      if(mapa[i][j] == '2') {
        pos2.pb(mp(i, j));
        mapa[i][j] = '.';
      }
    }
  }
  sort(pos2.begin(), pos2.end());

  /*
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      debug("%c", mapa[i][j]);
    }
    debug("\n");
  }
  */

  int d = bfs(field(pos1, pos2));
  if(d == -1) printf("NO SOLUTION\n");
  else printf("%d\n", d);
  return 0;
}