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

const int N = 1010;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
string ans[] = {"Right", "Left", "Front", "Back", "Over"};

bitset<N>v[N];
int n, m, sx, sy, px, py;

inline bool canDoThis(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m && v[x][y] == 0);
}

void dfs(int x, int y) {
  v[x][y] = 1;
  // if(x == px && y == py) {
  //   for(int i = 0; i < 4; ++i) {
  //     int xx = dx[i] + x, yy = dy[i] + y;
  //     if(canDoThis(xx, yy)) {
  //       printf("%s\n", ans[i].c_str());
  //       return;
  //     }
  //   }
  //   printf("%s\n", ans[4].c_str());
  //   return;
  // }

  for(int i = 0; i < 4; ++i) {
    int xx = dx[i] + x, yy = dy[i] + y;
    if(canDoThis(xx, yy)) {
      dfs(xx, yy);
      return;
    }
  }
  printf("%s\n", ans[4].c_str());
  return;

}

inline void main2() {
  scanf("%d %d %d %d", &n, &m, &sx, &sy);
  for(int i = 1; i <= n; ++i) v[i].reset();
  dfs(sx, sy);
  for(int i = 1; i <= n; ++i) {for(int j = 1; j <= m; ++j) { cout << v[i][j]; } printf("\n");}
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}