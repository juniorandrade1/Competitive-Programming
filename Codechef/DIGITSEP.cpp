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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 303;

char s[N];
int n, m, x, y;
int getVis[N][N];
int pd[N][N];
int countVis = 1;
ll glob;
set<ll>mySet;

inline void getDiv(ll x) {
  for(ll i = 1; i * i <= x; ++i) {
    if(x % i == 0) {
      mySet.insert(-i);
      mySet.insert(-(x / i));
    }
  }
}

bool dfs(int pos, int qtd) {
  if(qtd - 1 > y) return 0;
  if(pos == n) return (qtd - 1) >= x && (qtd - 1) <= y;
  if(getVis[pos][qtd] == countVis) return pd[pos][qtd];
  int ret = 0;
  ll f = 0;
  for(int i = 0; i < m && i + pos < n && !ret; ++i) {
    f *= 10LL;
    f += (ll)s[i + pos] - '0';
    if(f % glob == 0 || f == 0) {
      ret = dfs(i + pos + 1, qtd + 1);
    }
  }
  getVis[pos][qtd] = countVis;
  return pd[pos][qtd] = ret;
}

inline void main2() {
  mySet.clear();
  scanf("%d", &n);
  scanf(" %s", s);
  scanf("%d %d %d", &m, &x, &y);
  ll at = 0;
  int i = 0;
  while(i < n && s[i] == '0') i++;
  int st = i;
  for(; i < min(m + st, n); ++i) {
    at *= 10LL;
    at += (ll) (s[i] - '0');
    getDiv(at);
  }
  ll ans = 0;
  for(set<ll>::iterator it = mySet.begin(); it != mySet.end(); it++) {
    glob = -(*it);
    countVis += 10;
    if(dfs(0, 0)) {
      ans = glob;
      break;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}