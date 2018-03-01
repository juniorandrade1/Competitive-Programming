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
 
const int N = 100010;
 
int n, q;
ll a[N];
vi wi[N];
ll costInside[N];
ll p0[N], p1[N], wp[N];
 
inline ll getMinDistInsideCycle(int id, int l, int r) {
  if(l > r) swap(l, r);
  ll bt = wi[id][r - 1] - wi[id][l - 1];
  return min(bt, wi[id][a[id]] - bt); 
}
 
inline ll getCostInside(int l, int r) {
  if(r <= l - 1) return 0;
  return costInside[r] - costInside[l - 1]; 
}

inline ll getCostBetweenCycle(int l, int r) {
  if(r <= l - 1) return 0;  
  return wp[r] - wp[l - 1];
}

inline ll getDist(int v1, int c1, int v2, int c2) {
  if(c1 > c2) swap(c1, c2);
  ll cF = getCostBetweenCycle(c1, c2 - 1) + getCostInside(c1 + 1, c2 - 1) + getMinDistInsideCycle(c1, v1, p0[c1]) + getMinDistInsideCycle(c2, v2, p1[(c2 == 1) ? n : c2 - 1]);
  ll cB = getCostBetweenCycle(c2, n) + getCostBetweenCycle(1, c1 - 1) +
   getCostInside(c2 + 1, n) + getCostInside(1, c1 - 1) + 
   getMinDistInsideCycle(c1, v1, p1[(c1 == 1) ? n : c1 - 1]) + getMinDistInsideCycle(c2, v2, p0[c2]);
  return min(cF, cB);
}
 
inline void main2() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    wi[i].clear();
    wi[i].pb(0);
    for(int j = 1; j <= a[i]; ++j) {
      ll w; scanf("%lld", &w);
      wi[i].pb(w);
      wi[i][j] += wi[i][j - 1];
    }
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld", p0 + i, p1 + i, wp + i);
    wp[i] += wp[i - 1];
  }
  for(int i = 1; i <= n; ++i) {
    costInside[i] = getMinDistInsideCycle(i, p0[i], p1[(i == 1) ? n : (i - 1)]);
    costInside[i] += costInside[i - 1];
  }
  for(int i = 0; i < q; ++i) {
    int v1, c1, v2, c2;
    scanf("%d %d %d %d", &v1, &c1, &v2, &c2);
    printf("%lld\n", getDist(v1, c1, v2, c2));
  }
}
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}