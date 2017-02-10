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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define eps 1e-6

const int N = 1001;

int n, m;
char s[N][N];

inline void main2() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf(" %s", s[i]);

  for(int j = 0; j < m; ++j) {
    int lst;
    if(s[n - 1][j] == 'B') lst = 2;
    else if(s[n - 1][j] == 'W') lst = 1;
    else lst = 0;
    for(int i = n - 2; i >= 0; --i) {
      int foo = 0;
      if(s[i][j] == 'B') foo = 2;
      else if(s[i][j] == 'W') foo = 1;
      else foo = 0;
      if(foo > lst) {
        puts("no");
        return;
      }
      lst = foo;
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(s[i][j] == 'W') {
        if(j + 1 == m || j == 0) {
          puts("no");
          return;
        }
        if(j + 1 < m  && s[i][j + 1] == 'A') {
          puts("no");
          return;
        }
        if(j - 1 >= 0 && s[i][j - 1] == 'A') {
          puts("no");
          return;
        }
      }
    }
  }
  puts("yes");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}