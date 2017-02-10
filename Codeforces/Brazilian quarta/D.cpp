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
#define eps 1e-10

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1010;

vi g[N];
int n, m;
int dis[N];

void bfs(int st) {
  memset(dis, INF, sizeof dis);
  queue<int>q; q.push(st);
  dis[st] = 0;
  while(!q.empty()) {
    int x =  q.front(); q.pop();
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      if(dis[y] > dis[x] + 1) {
        dis[y] = dis[x] + 1;
        q.push(y);
      }
    }
  }
}

int pd[N][N];

int func(int x, int day) {
  //printf("%d %d\n", x, day);
  if(pd[x][day] != -1) return pd[x][day];
  if(day % 2 == 0) {
    int ret = 1;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      if(day + 1 <= dis[y] && func(y, day + 1) == 0) ret = 0;
    }
    pd[x][day] = ret;
  }
  else {
    int ret = 0;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      if(day + 1 <= dis[y] && func(y, day + 1) == 1) ret = 1;
    }
    return pd[x][day] = ret;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  bfs(0);
  memset(pd, -1, sizeof pd);
  puts(func(0, 0) ? "Nikolay" : "Vladimir");
  return 0;
}