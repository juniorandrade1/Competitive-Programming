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
int a[N];

int vis[N];
vi S;
ll cnt = 0;
int hasCycle[N];
ll ans = 1;

ll mmc(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

void dfs(int x) {
  S.pb(x);
  vis[x] = 1;
  int y = a[x];
  if(vis[y]) {
    int id = S.size() - 1;
    debug("%d %d\n", x, id);
    while(1) {
      hasCycle[S[id]] = 1;
      cnt++;
      if(S[id] == y) break;
      id--;
    }
  }
  else dfs(y);
  S.pop_back();
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }

  for(int i = 1; i <= n; ++i) {
    cnt = 1;
    memset(vis, 0, sizeof vis);
    int foo = a[i];
    int ok = 0;
    while(1) {
      if(vis[foo]) break;
      vis[foo] = 1;
      if(foo == i) {
        ok = 1;
        break;
      }
      cnt++;
      foo = a[foo];
    }

    if(!ok) {
      puts("-1");
      exit(0);
    } 

    if(cnt % 2 == 0) cnt /= 2;
    ans = mmc(ans, cnt);
  }

  printf("%lld\n", ans);


  return 0;
}