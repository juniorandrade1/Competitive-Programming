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

const int M = 18;
const int N = (1 << M);

int n;
ll v[N];
bitset< N > vis;
ll ans = 0;

void affect(int x, ll y) {
  if(vis[x]) return;
  if(v[x] <= 0) ans++;
  v[x] -= y;
  if(v[x] <= 0) ans--;
  vis[x] = 1;
  if(x == 0) return;
  for(int i = 0; i < M; ++i) if((x >> i) & 1) affect(x ^ (1 << i), y);

}
 
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  ans = n;
  int q; scanf("%d", &q);
  while(q--) {
    ll x, y; scanf("%lld %lld", &x, &y);
    vis.reset();
    x &= (N - 1);
    affect(x, y);
    printf("%lld\n", ans);
  }
  return 0;
} 