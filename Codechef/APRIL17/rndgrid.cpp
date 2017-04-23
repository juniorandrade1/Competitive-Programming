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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int N = 1010;
const int L = 5010;

char s[L], v[N][N];
int n, l;

inline bool check(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n && v[x][y] == '.';
}

inline int getId(char c) {
  if(c == 'U') return 0;
  if(c == 'R') return 1;
  if(c == 'D') return 2;
  if(c == 'L') return 3;
}

inline bool existBlock() {
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(v[i][j] == '#') return true;
  return false;
}

int pdMinX[L], pdMinY[L], pdMaxX[L], pdMaxY[L];
int pd[N][N][2];

inline void main2() {
  scanf("%d %d", &l, &n);
  scanf(" %s", s);
  for(int i = 0; i < n; ++i) scanf(" %s", v[i]);
  int ans = 0;
  if(existBlock()) {
    memset(pd, 0, sizeof pd);
    for(int z = l - 1; z >= 0; --z) {
      int nxt = 1 - (z & 1);
      for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          pd[i][j][z & 1] = 0;
          if(check(i, j) == false) continue;
          int xx = i + dx[getId(s[z])], yy = j + dy[getId(s[z])];
          if(check(xx, yy)) pd[i][j][z & 1] = pd[xx][yy][nxt] + 1;
          if(z == 0) ans ^= pd[i][j][z & 1];
        }
      }
    }
  }
  else {
    int atX = 0, atY = 0;
    for(int i = 0; i < l; ++i) {
      atX += dy[getId(s[i])];
      atY += dx[getId(s[i])];
      pdMinX[i + 1] = min(pdMinX[i], atX);
      pdMaxX[i + 1] = max(pdMaxX[i], atX);
      pdMinY[i + 1] = min(pdMinY[i], atY);
      pdMaxY[i + 1] = max(pdMaxY[i], atY);
    }
    for(int i = 0; i < n; ++i) {     
      for(int j = 0; j < n; ++j) {
        if(check(i, j) == false) continue;
        int lo = 0, hi = l;
        while(lo < hi) {
          int mid = (lo + hi + 1) >> 1;
          if(i + pdMinX[mid] < 0 || i + pdMaxX[mid] >= n || j + pdMinY[mid] < 0 || j + pdMaxY[mid] >= n) hi = mid - 1;
          else lo = mid;
        } 
        ans ^= lo;
      }
    }
  }
  printf("%d\n", ans);
}
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
} 