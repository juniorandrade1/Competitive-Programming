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

void arquivo() {
  freopen("settling.in", "r", stdin);
  freopen("settling.out", "w", stdout);
}

const int N = 202;

int n, m;
int g[N][N];
bitset<N>vis[N];
int qtd = 0;




int main() {
  arquivo();
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g[a][b] = 1;
  }

  qtd = 0;
  for(int i = n - 1; i >= 0; --i) {
    vis[i].reset();
    vis[i][i] = 1;
    for(int j = i + 1; j < n; ++j) if(g[i][j]) vis[i] |= vis[j];
    qtd += (vis[i].count() - 1);
  }


  printf("%d\n", qtd);
  int q; scanf("%d", &q);
  while(q--) {
    char c; int a, b;
    scanf(" %c %d %d", &c, &a, &b);
    a--; b--;
    if(c == '?') puts(vis[a][b] ? "YES" : "NO");
    else {
      if(c == '-') g[a][b] = 0;
      else g[a][b] = 1;
      for(int i = a; i >= 0; --i) {
        qtd -= (vis[i].count() - 1);
        vis[i].reset();
        vis[i][i] = 1;
        for(int j = i + 1; j < n; ++j) if(g[i][j]) vis[i] |= vis[j];
        qtd += (vis[i].count() - 1);
      }
      printf("%d\n", qtd);
    }
  }
  return 0;
}