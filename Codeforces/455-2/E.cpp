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

#define pi acos(-1.0)

const int N = 100010;

int n, m;
int t[N];
int deg[N];
vi g[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%d", t + i);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    deg[a]++;
    g[b].pb(a);
  }
  queue< int > q[2];
  for(int i = 0; i < n; ++i) {
    if(deg[i] == 0) q[t[i]].push(i);
  }
  int sol = 0;
  int op = 0;
  while(!q[0].empty() || !q[1].empty()) {
    if(q[op].empty()) {
      sol += (op == 0);
      op ^= 1;
      continue;
    }
    int x = q[op].front(); q[op].pop();
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      deg[y]--;
      if(deg[y] == 0) {
        q[t[y]].push(y);
      }
    }
  }
  printf("%d\n", sol);
  return 0;
}