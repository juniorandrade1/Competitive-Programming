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

const int N = 110;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char v[N][N];
int n, m;
int idV[N][N], cnt = 0;
set<int>vMsk;
vi all;
int pd[100][1 << 15];

int func(int pos, int mask) {
  if(pos == all.size()) return (mask == (1 << cnt) - 1) ? 0 : INF;
  if(pd[pos][mask] != -1) return pd[pos][mask];
  int ret = min(func(pos + 1, mask), func(pos + 1, mask | all[pos]) + 1);
  return pd[pos][mask] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", v[i]);
    for(int j = 0; j < m; ++j) {
      if(v[i][j] == 'T') idV[i][j] = cnt++;
    }
  }
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    if(v[i][j] == 'T') continue;
    int msk = 0;
    for(int k = 0; k < 8; ++k) {
      int ii = i + dx[k], jj = j + dy[k];
      if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
      if(v[ii][jj] == 'T') msk |= (1 << idV[ii][jj]);
    }
    if(msk) vMsk.insert(msk);
  }
  for(set<int>::iterator it = vMsk.begin(); it != vMsk.end(); it++) all.pb(*it);
  memset(pd, -1, sizeof pd);
  int sol = func(0, 0);
  if(sol == INF) puts("IMPOSSIVEL");
  else printf("%d\n", sol);
  return 0;
}
