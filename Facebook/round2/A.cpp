#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

ll n, m, k;

inline ll go(ll a, ll b) {
  if(a == 1 || b == 1) return LINF;
  b -= k * 2 + 3;
  if(b < 0) return LINF;
  ll aa = a - 2 * k - 1;
  //if(aa < 0) return LINF;
  ll ans = min((a + k - 1) / k, 5LL);
  //assert(ans != 1);
  return ans;
}

inline void main2() {
  scanf("%lld %lld %lld", &n, &m, &k);
  if(k >= n || k >= m) {
    puts(" -1");
    return;
  }
  ll ans = go(min(n, m), max(n, m));
  if(ans == LINF) puts(" -1");
  else printf(" %lld\n", ans);
}

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}