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

const int N = 555;

char s[N][N];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  int xMin, xMax, yMin, yMax;
  xMin = yMin = INF;
  xMax = yMax = -INF;
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s[i]);
    for(int j = 0; j < m; ++j) {
      if(s[i][j] == 'X') {
        xMin = min(xMin, i);
        xMax = max(xMax, i);
        yMin = min(yMin, j);
        yMax = max(yMax, j);

      }
    }
  }
  for(int i = xMin; i <= xMax; ++i) {
    for(int j = yMin; j <= yMax; ++j) {
      if(s[i][j] == '.') {
        puts("NO");
        exit(0);
      }
    }
  }
  puts("YES");
  return 0;
}