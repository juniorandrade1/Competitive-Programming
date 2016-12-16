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

const int N = 110;


int n;  
vi all[N];
vi g[N];

void dfs(int x, int ult = 0) {
  for(int i = 0; i < all[x].size(); ++i) if(ult != all[x][i]) {
    g[x].pb(all[x][i]);
    dfs(all[x][i], x);
  }
}

int sol[N];

int func(int x) {
  int o1 = 0, o2 = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    int foo = func(y);
    if(foo == 1) o1 = 1;
    if(foo == 2) o2 = 1;
  }
  if(o1) {
    sol[x] = 1;
    return 2;
  }
  if(o2) return 0;
  if(x == 0) {
    sol[x] = 1;
    return 2;
  }
  return 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    all[a].pb(b);
    all[b].pb(a);
  }
  dfs(0, 0);
  func(0);
  for(int i = 0; i < n; ++i) printf("%d ", sol[i]);
  printf("\n");

  return 0;
}