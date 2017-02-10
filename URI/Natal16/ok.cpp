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

const int N = 100010;

ll x[N], c[N];
int n;
ll pd[N];

/*
int memo[N];
ll func(int pos) {
  if(pos == n) return 0;
  if(memo[pos]) return pd[pos];
  ll ret = func(pos + 1);
  for(int i = pos + 1; i < n; ++i) {
    ll d = x[i] - x[pos];
    ret = max(ret, func(i) + d * x[pos] - c[pos]);
  }
  return pd[pos] = ret;
}
*/

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

HullDynamic hd;

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld %lld", x + i, c + i);
    for(int i = n; i >= 0; --i) {
      if(n == i) pd[i] = -c[i];
      else pd[i] = -LINF;
      for(int j = i + 1; j <= n; ++j) {
        ll sol = x[j] * x[i] + pd[j] - x[i] * x[i] - c[i];
        pd[i] = max(pd[i], sol);
      }
    }
    debug("%lld\n", pd[0]);
  }
  return 0;
}