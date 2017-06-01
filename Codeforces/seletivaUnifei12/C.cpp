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

const int N = 1000001;

int n;

map<string, int> idx;
int cntIdx = 0;

inline int getIdx(string s) {
  if(idx.find(s) == idx.end()) idx[s] = cntIdx++;
  return idx[s];
}

char s[N];
vi g[N];
int dp[N];

int func(int x) {
  if(g[x].size() == 0) return 1;
  if(dp[x] != -1) return dp[x];
  int ret = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    ret = max(ret, 1 + func(y));
  }
  return dp[x] = ret;
}

int main() {
  while(scanf("%d", &n) && n > 0) {
    idx.clear();
    cntIdx = 0;
    for(int i = 0; i < n; ++i) {
      g[i].clear();
      dp[i] = -1;
    }
    for(int i = 0; i < n; ++i) {
      scanf(" %s", s);
      int t; scanf("%d", &t);
      int x = getIdx((string)s);
      for(int j = 0; j < t; ++j)  {
        scanf(" %s", s);
        int y = getIdx((string)s);
        g[x].pb(y);
      }
    }
    int ans = 0;
    for(int i = 0; i < cntIdx; ++i) ans = max(ans, func(i));
    printf("%d\n", ans);
  }
  return 0;
}