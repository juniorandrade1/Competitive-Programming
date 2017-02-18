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

const int N = 2001;

#define pi acos(-1.0)
#define eps 1e-6

struct Point {
  ll x, y;
  Point(){};
  void read(){ scanf("%lld %lld", &x, &y); }
};

struct Tree {
  Point p;
  ll w;
  int type;
  Tree(){};
  Tree(Point _p, ll _val, int _type) {
    p = _p;
    type = _type;
    w = _val;
  }
};

inline bool above(const Tree &t) {
  if (t.p.y == 0) return t.p.x > 0;
  return t.p.y > 0;
}

inline bool below(const Tree &t) {
  return !above(t);
}

bool cmp(const Tree &a, const Tree &b) {
    long long cross = 1LL * a.p.x * b.p.y - 1LL * a.p.y * b.p.x;
    if (!above(a)) cross = -cross;
    if (!above(b)) cross = -cross;
    return cross > 0;
}

bool equal(const Tree &a, const Tree &b) {
  long long cross = 1LL * a.p.x * b.p.y - 1LL * a.p.y * b.p.x;
  return cross == 0;
}

int p, l, n;
Tree tr[N];
Tree sline[N];
int orderByAngle[N];

ll solve(int op) {
  sort(sline, sline + n, cmp);
  ll foo = 0;
  for (int i = 0; i < n; ++i) {
    if (above(sline[i]) && sline[i].type != op) foo += sline[i].w;
    if (below(sline[i]) && sline[i].type == op) foo += sline[i].w;
  }
  ll ans = foo;
  for (int i = 0, j; i < n; i = j) {
    j = i;
    while (j < n and equal(sline[j], sline[i])) {
      if (above(sline[j])) {
        if (sline[j].type == op) foo += sline[j].w;
        else foo -= sline[j].w;
      }
      if (below(sline[j]) ) {
        if (sline[j].type != op) foo += sline[j].w;
        else foo -= sline[j].w;
      }
      j++;
    }
    ans = min(ans, foo);
  }
  return ans;
}

int main() {
  while(1) {
  scanf("%d %d", &p, &l);
  if(p == l && p == 0) break;
  for(int i = 0; i < p; ++i) {
      Point pt; pt.read();
      ll w; scanf("%lld", &w);
      tr[i] = Tree(pt, w, 0);
      orderByAngle[i] = i;
    }
    for(int i = 0; i < l; ++i) {
      Point pt; pt.read();
      ll w; scanf("%lld", &w);
      tr[i + p] = Tree(pt, w, 1);
      orderByAngle[i + p] = i + p;
    }
    n = p + l - 1;
    ll ans = LINF;
    for(int i = 0; i <= n; ++i) {
      int m = 0;
      for(int j = 0; j <= n; ++j) {
        if(i == j) continue;
        sline[m] = tr[j];
        sline[m].p.x -= tr[i].p.x;
        sline[m].p.y -= tr[i].p.y;
        m++;
      }
      ans = min(ans, solve(0));
      ans = min(ans, solve(1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}