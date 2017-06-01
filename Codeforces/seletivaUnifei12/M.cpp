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

const int MAXN = 110;
int n, g[MAXN][MAXN];
int best_cost = 1000000000;
vector<int> best_cut;

void mincut() {
  vector<int> v[MAXN];
  for (int i=0; i<n; ++i) v[i].assign (1, i);
  int w[MAXN];
  bool exist[MAXN], in_a[MAXN];
  memset (exist, true, sizeof exist);
  for (int ph=0; ph<n-1; ++ph) {
    memset (in_a, false, sizeof in_a);
    memset (w, 0, sizeof w);
    for (int it=0, prev; it<n-ph; ++it) {
    int sel = -1;
    for (int i=0; i<n; ++i) if (exist[i] && !in_a[i] && (sel == -1 || w[i] > w[sel])) sel = i;
    if (it == n-ph-1) {
      if (w[sel] < best_cost) best_cost = w[sel], best_cut = v[sel];
      v[prev].insert (v[prev].end(), v[sel].begin(), v[sel].end());
      for (int i=0; i<n; ++i) g[prev][i] = g[i][prev] += g[sel][i];
      exist[sel] = false;
    }
    else {
        in_a[sel] = true;
        for (int i=0; i<n; ++i) w[i] += g[sel][i];
        prev = sel;

      }
    }
  }
}

int m;

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    if(n <= 1) {
      puts("0");
      continue;
    }
    best_cost = 1000000000;
    best_cut.clear();
    memset(g, 0, sizeof g);
    for(int i = 0; i < m; ++i) {
      int x, y;
      char a, b, c;
      scanf(" %c %d %c %d %c", &a, &x, &b, &y, &c);
      g[x][y]++;
      g[y][x]++;
    }
    mincut();
    printf("%d\n", best_cost);
  }
  return 0;
}