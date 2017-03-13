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

const int N = 14;

set<ll>s;
int n, m;
ll a[N], b[N];
set<ll>allComb;

inline void back(int pos, ll dir, ll esq) {
  if(dir == esq) allComb.insert(dir + esq);
  if(pos == m) return;
  back(pos + 1, dir, esq);
  back(pos + 1, dir + b[pos], esq);
  back(pos + 1, dir, esq + b[pos]);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i);
  for(int i = 0; i < m; ++i) scanf("%lld", b + i);
  back(0, 0, 0);
  for(int i = 0; i < n; ++i) for(set<ll>::iterator it = allComb.begin(); it != allComb.end(); it++) s.insert((*it) + a[i]);
  for(set<ll>::iterator it = s.begin(); it != s.end(); it++) printf("%lld\n", *it);
  return 0;
}