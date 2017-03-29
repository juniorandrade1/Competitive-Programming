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

const int N = 1e6 + 10;


int n, m;
vi g[N];
// ll pd1[N], pd2[N];

// ll calc2(int pai, int id, int avo) {
//   if(g[pai].size() == id) return 1;
//   int x = g[pai][id];
//   if(x == avo) return calc2(pai, id + 1, avo);
//   if(pd1[x] != -1) return pd1[x];
//   ll ret = calc2(x, 0, pai) * calc2(pai, id + 1, avo);
//   return pd1[x] = ret;
// }

// ll calc1(int pai, int id, int avo) {
//   if(g[pai].size() == id) return 1;
//   int x = g[pai][id];
//   if(x == avo) return calc1(pai, id + 1, avo);
//   if(pd2[x] != -1) return pd2[x];
//   ll ret = calc1(x, 0, pai) * calc1(pai, id + 1, avo);
//   return pd1[x] = ret;
// }

ll pdOld[N];

ll dfs(int x, int ult) {
  if(pdOld[x] != -1) return pdOld[x];
  ll ret = 0;
  int qtd = 0;
  ll sum = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    if(g[x][i] == x)  {
      qtd++;
      sum++;
    }
    else {
      if(g[x][i] == ult) continue;
      qtd++;
      sum += dfs(g[x][i], x);
    }
  }
  if(qtd == 0) return pdOld[x] = 1;
  for(int i = 0; i < g[x].size(); ++i) {
    if(g[x][i] == x) { 
      ret += sum - 1;
    }
    else if(g[x][i] == ult) continue;
    else {
      ll q = dfs(g[x][i], x);
      sum -= q;
      ret += sum * q;
      sum += q;
    }
  }
  return pdOld[x] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g[a].pb(b);
  }
  //memset(pd1, -1, sizeof pd1);
  //memset(pd2, -1, sizeof pd2);
  memset(pdOld, -1, sizeof pdOld);

  int diff = 0;
  ll ans = 0;
  for(int i = 0; i < n; ++i) if(pdOld[i] == -1) {
    diff += (dfs(i, i) != 0);
    ans += dfs(i, i);
    //diff += calc2(i, 0, i) != 0;
    //ans += calc2(i, 0, i);
    //calc1(i, 0, i);
  }
  if(diff > 1) {
    puts("0");
    exit(0);
  }
  printf("%lld\n", ans / 2);
  return 0;
}