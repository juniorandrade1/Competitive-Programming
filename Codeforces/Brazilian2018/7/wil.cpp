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

const int N = 2000001;

int n, d;
ll p;
ll v[N], c[N];
multiset< ll > s;

int main() {
  scanf("%d %lld %d", &n, &p, &d);
  for(int i = 1; i <= n; ++i) scanf("%lld", v + i), c[i] = c[i - 1] + v[i];
  int ans = min(d, n);
  int l = 0;
  for(int r = d; r <= n; ++r) {
    s.insert(c[r] - c[r - d]);
    while(s.size() && c[r] - c[l] - *s.rbegin() > p) {
      s.erase(s.find(c[l + d] - c[l]));
      l++;
    }
    ans = max(ans, r - l);
  }
  printf("%d\n", ans);

} 