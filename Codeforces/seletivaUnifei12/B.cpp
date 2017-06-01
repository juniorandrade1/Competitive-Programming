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

const int N = 500002;

int n, u, d, s;

struct node {
  int t, l, m, id;
  node(){};
  node(int _t, int _l, int _m) {
    t = _t;
    l = _l;
    m = _m;
  }
  bool operator < (node foo) const {
    if(t != foo.t) return t < foo.t;
    return l < foo.l;
  }

  void read(int _id) {
    id = _id;
    scanf("%d %d %d", &t, &l, &m);
  }
};

node v[N];
ll pd[N];

ll func(int pos) {
  if(pos == n + 1) return 0;
  if(pd[pos] != -1) return pd[pos];
  ll ret = 0;
  ll ds = abs(v[pos].l - s);
  if(v[pos].l > s) ret = v[pos].m - (ds * u);
  else ret = v[pos].m - (ds * d);
  for(int i = pos + 1; i <= n; ++i) {
    ll at = v[pos].m;
    ds = abs(v[pos].l - v[i].l);
    if(v[pos].l > v[i].l) at -= (ds * u);
    else at -= (ds * d);
    ret = max(ret, at + func(i));
  }
  return pd[pos] = ret;
}

int main() {
  while(1) {
    scanf("%d %d %d %d", &n, &u, &d, &s);
    if(n == 0 && u == 0 && d == 0 && s == 0) break;
    for(int i = 0; i <= n; ++i) pd[i] = -1;
    for(int i = 1; i <= n; ++i) v[i].read(i);
    v[0].l = s;
    v[0].t = -1;
    v[0].m = 0;
    sort(v + 1, v + n + 1);
    for(int i = n; i >= 0; --i) func(i);
    printf("%lld\n", func(0));
  }
  return 0;
}
