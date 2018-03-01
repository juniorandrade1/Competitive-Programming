#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

HullDynamic ch;

struct Equation {
  ll a[4];
  Equation(){};
  void read() {
    scanf("%lld %lld %lld %lld", a + 0, a + 1, a + 2, a + 3);
  }
  ll eval(ll x) {
    ll p = 1;
    ll ans = 0;
    for(int i = 0; i < 4; ++i) {
      ans += p * a[i];
      p *= x;
    }
    return ans;
  }
};

struct Query {
  ll t;
  int idx;
  Query(){};
  Query(ll _t, int _idx) {
    t = _t;
    idx = _idx;
  }
  bool operator < (Query other) const {
    return t < other.t;
  }
};


const int N = 100010;

int n, q;
Equation eq[N];
Query que[N];
ll sol[N];

inline bool allEquationsAreLines() {
  bool ok = true;
  for(int i = 0; i < n; ++i) {
    ok &= (eq[i].a[3] == 0 && eq[i].a[2] == 0);
  }
  return ok;
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) eq[i].read();
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    ll t; scanf("%lld", &t);
    que[i] = Query(t, i);
  }
  sort(que, que + q);
  if(n <= 1000 && q <= 1000) { //BruteForce solution
    for(int i = 0; i < q; ++i) {
      ll ans = 0x3f3f3f3f3f3f3f3fLL;
      for(int j = 0; j < n; ++j) {
        ans = min(ans, eq[j].eval(que[i].t));
      } 
      sol[que[i].idx] = ans;
    }
  }
  else if(allEquationsAreLines()) {
    ch = HullDynamic();
    for(int i = 0; i < n; ++i) {
      ch.insert_line(-eq[i].a[1], -eq[i].a[0]);
    }
    for(int i = 0; i < q; ++i) {
      sol[que[i].idx] = -ch.eval(que[i].t);
    }
  }
  else { //SOON
  }


  for(int i = 0; i < q; ++i) printf("%lld\n", sol[i]);
}

int main() {
  int test; scanf("%d", &test);
  for(int t = 1; t <= test; ++t) {
    main2();
  }
  return 0;
}