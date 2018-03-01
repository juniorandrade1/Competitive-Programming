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

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 505;


int n, m;
int v[N][N];
vector< int > g[N * N];
int sol[N][N];
int qtd[N * N];

int dfs(int x, int ult) {
  qtd[x] = 1;
  for(int i = 0; i < (int)g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    qtd[x] += dfs(y, x);
  }
  return qtd[x];
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      scanf("%d", &v[i][j]);
    }
  }
  vector< int > root;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      int x = -1, y = -1, ls = v[i][j];
      for(int k = -1; k <= 1; ++k) {
        for(int l = -1; l <= 1; ++l) {
          if(!k && !l) continue;
          int xx = i + k, yy = j + l;
          if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
          if(v[xx][yy] < ls) {
            x = xx;
            y = yy;
            ls = v[xx][yy];
          }
        }
      }
      if(x == -1 || y == -1) {
        root.pb(i * m + j);
      }
      else {
        g[x * m + y].pb(i * m + j);
      }
    }
  }
  for(int i = 0; i < (int)root.size(); ++i) {
    int x = root[i];
    sol[x / m][x % m] = dfs(x, x);
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      printf("%d ", sol[i][j]);
    }
    printf("\n");
  }
  return 0;
}