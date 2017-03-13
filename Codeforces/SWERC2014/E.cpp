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

int r, n, m, maximum;

struct field {
  vector< string > v;
  field();
  field(vector< string > other) {
    v = other;
  }
  bool operator < (field other) const {
    return v < other.v;
  }
};

map< field, int > dis;

bool finishField(field f) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(f.v[i][j] == 'X') return false;
    }
  }
  return true;
}

inline void printField(field foo) {
  for(int i = 0; i < n; ++i) cout << foo.v[i] << endl;
  cout << endl;
}

int bfs(field start) {
  queue< field > q; q.push(start); dis[start] = 0;
  while(!q.empty()) {
    field foo = q.front(); q.pop();
    field cp = foo;
    if(finishField(foo)) {
      return dis[foo];
    }
    if(dis[foo] == maximum) break;
    int wwwwwww = dis[foo];
    for(int x = 0; x < n; ++x) {
      for(int y = 0; y < m; ++y) {
        if(foo.v[x][y] == '.' || foo.v[x][y] == 'W' || foo.v[x][y] == 'X') continue;
        for(int k = 0; k < 4; ++k) {
          int z = 1;
          while(1) {
            int xx = x + dx[k] * z, yy = y + dy[k] * z;
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) break;
            if(foo.v[xx][yy] == '.' || foo.v[xx][yy] == 'X') {
              z++;
            }
            else break;
          }
          if(z == 1) continue;
          int xx = x  + dx[k] * (z - 1), yy = y + dy[k] * (z - 1);
          char pxy = foo.v[x][y], pxxyy = foo.v[xx][yy];
          if(pxxyy == 'X' && (pxy - '0') >= 2 && (pxy - '0') <= 4) continue;
          foo.v[xx][yy] = foo.v[x][y];
          foo.v[x][y] = '.';
          if(dis.find(foo) == dis.end()) {
            dis[foo] = wwwwwww + 1;
            q.push(foo);
          }
          foo.v[x][y] = pxy;
          foo.v[xx][yy] = pxxyy;
        }
      }
    }
    //exit(0);
  }
  return -1;
}

int main() {
  scanf("%d %d %d %d", &r, &m, &n, &maximum);
  vector< string > f;
  for(int i = 0; i < n; ++i) {
    char s[123]; scanf(" %s", s);
    for(int j = 0; j < m; ++j) if(s[j] >= '2' && s[j] <= '5') s[j] = '2';
    f.pb((string)s);
  }
  int d = bfs(field(f));
  if(d == -1) printf("NO SOLUTION\n");
  else printf("%d\n", d);
  return 0;
}