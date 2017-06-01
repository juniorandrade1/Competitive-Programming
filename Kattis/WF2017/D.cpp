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

const int N = 500500;

int n, m;
vii a, b;

bool cmpY(ii a, ii b) {
  if(a.S != b.S) return a.S < b.S;
  return a.F < b.F;
}

ll solve(int lx, int rx, int ly, int ry) {
  if(lx > rx) return 0;
  int mid = (lx + rx) >> 1;
  int bst = -1;
  ll ans = -LINF;
  for(int i = ly; i <= ry; ++i) {
    if(b[i] <= a[mid]) continue;
    ll at = (b[i].F - a[mid].F) * (b[i].S - a[mid].S);
    if(at > ans) {
      bst = i;
      ans = at;
    }
  }
  if(bst == -1) return 0;
  ll p1 = solve(lx, mid - 1, ly, bst);
  ll p2 = solve(mid + 1, rx, bst, ry);
  return max(ans, max(p1, p2));
}

int main() {
  scanf("%d %d", &m, &n);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    a.pb(mp(x, y));
  }
  for(int i = 0; i < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    b.pb(mp(x, y));
  }
  sort(a.rbegin(), a.rend());
  set< ii, bool(*)(ii, ii) > sa(cmpY);
  for(int i = 0; i < m; ++i) {
    sa.insert(a[i]);
    set< ii, bool(*)(ii, ii)> ::iterator it;
    while(1) {
      it = sa.upper_bound(a[i]);
      if(it != sa.end()) sa.erase(it);
      else break;
    }
  }
  a.clear();
  for(set< ii, bool(*)(ii, ii)> ::iterator it = sa.begin(); it != sa.end(); it++) a.pb(*it);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  set< ii, bool(*)(ii, ii) > sb(cmpY);
  for(int i = 0; i < n; ++i) {
    sb.insert(b[i]);
    set< ii, bool(*)(ii, ii)> ::iterator it = sb.lower_bound(b[i]);
    while(sb.begin() != it) sb.erase(sb.begin());
  }
  b.clear();
  for(set< ii, bool(*)(ii, ii)> ::iterator it = sb.begin(); it != sb.end(); it++) b.pb(*it);
  sort(b.begin(), b.end());
  printf("%lld\n", solve(0, a.size() - 1, 0, b.size() - 1));
  return 0;
}
