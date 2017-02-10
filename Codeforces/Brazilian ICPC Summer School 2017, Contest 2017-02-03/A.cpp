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

const int N = 510;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int v[N][N];
int pass[N][N];
char s[N * N];

int getVal(int x, int y) {
  pass[x][y]++;
  if(pass[x][y] == 1) return v[x][y];
  else return v[x][y] / 2;
}

int main() {
  arquivo();
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%1d", &v[i][j]);
  scanf(" %s", s);
  int len = strlen(s);
  ll sum = 0;

  int x = 0, y = 0;
  int dir = 1;
  for(int i = 0; i < len; ++i) {
    if(s[i] == 'R') dir += 3;
    else if(s[i] == 'L') dir++;
    if(dir >= 4) dir -= 4;

    if(s[i] == 'M') {
      if(dir == 0) {
        sum += getVal(x + 1, y) + getVal(x + 1, y + 1);
      }
      else if(dir == 1) {
        sum += getVal(x, y + 1) + getVal(x + 1, y + 1);
      }
      else if(dir == 2) {
        sum += getVal(x, y) + getVal(x, y + 1);
      }
      else if(dir == 3) {
        sum += getVal(x, y) + getVal(x + 1, y);
      }
      x += dx[dir];
      y += dy[dir];
    }
  }
  printf("%lld\n", sum);
  return 0;
}