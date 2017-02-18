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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 100010;

vi g1[N], g2[N];
int c1[N], c2[N];
int d1[N], d2[N];
int n, m;

void dfs1(int x, int ult) {
  d1[x] = g1[x].size();
  for(int i = 0; i < g1[x].size(); ++i) {
    int y = g1[x][i];
    if(y == ult) continue;
    c1[y] = 1 - c1[x];
    dfs1(y, x);
  }
}

void dfs2(int x, int ult) {
  d2[x] = g2[x].size();
  for(int i = 0; i < g2[x].size(); ++i) {
    int y = g2[x][i];
    if(y == ult) continue;
    c2[y] = 1 - c2[x];
    dfs2(y, x);
  }
}

int main() {
  //arquivo();
  scanf("%d", &n);
  for(int i = 0; i + 1 < n; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g1[a].pb(b);
    g1[b].pb(a);
  }

  scanf("%d", &m);
  for(int i = 0; i + 1 < m; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g2[a].pb(b);
    g2[b].pb(a);
  }

  dfs1(0, 0);
  dfs2(0, 0);



  vi count1[2];
  memset(count1, 0, sizeof count1);
  for(int i = 0; i < n; ++i) if(d1[i] == 1) count1[c1[i]].pb(i);

  vi count2[2];
  memset(count2, 0, sizeof count2);
  for(int i = 0; i < m; ++i) if(d2[i] == 1) count2[c2[i]].pb(i);

  int cr1[2], cr2[2];
  cr1[0] = count1[0].size();
  cr1[1] = count1[1].size();
  cr2[0] = count2[0].size();
  cr2[1] = count2[1].size();

  if(cr1[0] == cr2[0] && cr1[1] == cr2[1]) {
    printf("2\n");
    for(int z = 0; z < 2; ++z) {
      for(int i = 0; i < cr1[z]; ++i) {
        printf("%lld %lld\n", count1[z][i] + 1, count2[z][i] + 1);
      }
    }
  }
  else if(cr1[0] == cr2[1] && cr1[1] == cr2[0]) {
    printf("2\n");
    for(int z = 0; z < 2; ++z) {
      for(int i = 0; i < cr1[z]; ++i) {
        printf("%lld %lld\n", count1[z][i] + 1, count2[z ^ 1][i] + 1);
      }
    }
  }
  else {
    printf("3\n");
    vi a1, a2;
    for(int z = 0; z < 2; ++z) for(int i = 0; i < cr1[z]; ++i) a1.pb(count1[z][i]);
    for(int z = 0; z < 2; ++z) for(int i = 0; i < cr2[z]; ++i) a2.pb(count2[z][i]);
    for(int i = 0; i < min(a1.size(), a2.size()); ++i) printf("%lld %lld\n", a1[i] + 1, a2[i] + 1);
  }
  return 0;
}