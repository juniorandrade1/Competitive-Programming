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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1, -1, 0, 1};

char t[4][4];

inline void print() {
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      debug("%c", t[i][j]);
    }
    debug("\n");
  }
}

bool check() {
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      for(int k = 0; k < 8; ++k) {
        int px1 = i + dx[k], py1 = j + dy[k];
        int px2 = i + 2 * dx[k], py2 = j + dy[k] * 2;
        if(px2 < 0 || px2 >= 4 || py2 < 0 || py2 >= 4) continue;
        if(t[i][j] == 'x' && t[px1][py1] == 'x' && t[px2][py2] == 'x') {
          //debug("%d %d - %d %d - %d %d = %d\n", i, j, px1, py1, px2, py2, k);
          //print();
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < 4; ++i) scanf(" %s", t[i]);
  for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) if(t[i][j] == '.') {
    t[i][j] = 'x';
    if(check()) {
      puts("YES");
      exit(0);
    }
    t[i][j] = '.';
  }
  puts("NO");
  return 0;
}