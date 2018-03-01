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

const int N = 1001;
const int M = 4;

int n;
int a[M];
char s[M][N];
unordered_map<int, int> pd[M][N];
int all[M];   

int func(int x, int y, int mask) {
  if(y == n) return (mask == 0) ? 0 : INF;
  if(x == M) return func(0, y + 1, mask);
  if(pd[x][y].find(mask) != pd[x][y].end()) return pd[x][y][mask];
  int ret = INF;
  int ok = (s[x][y] == '.' || (mask & 1));
  if(ok) ret = func(x + 1, y, mask >> 1);
  for(int i = 1; i <= M; ++i) {
    int nmask = ((mask | all[i - 1]));
    if(x + i <= M) {
      ret = min(ret, func(x + 1, y, nmask >> 1) + a[i - 1]);
    }
  }
  return pd[x][y][mask] = ret;
}

int main() {
  all[0] = (1 << 0);
  all[1] = ((1 << 0) | (1 << 1) | (1 << 4) | (1 << 5));
  all[2] = (all[1] | (1 << 2) | (1 << 6) | (1 << 8) | (1 << 9) | (1 << 10));
  all[3] = (1 << 16) - 1;
  scanf("%d", &n);
  for(int i = 0; i < M; ++i) scanf("%d", a + i);
  for(int i = 0; i < M; ++i) scanf(" %s", s[i]);
  printf("%d\n", func(0, 0, 0));
  return 0;
}