#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

struct Line {
  ll a, b;
  Line(){};
  Line(ll _a, ll _b) {
    a = _a;
    b = _b;
  }
  ll eval(ll x) {
    return a * x + b;
  }
  bool operator < (Line other) {
    if(a != other.a) return a < other.a;
    return b < other.b;
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

const int N = 300010;

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

bool removeConvexHull(Line l1, Line l2, Line l3) {
  return (l1.a - l2.a) * (l3.b - l1.b) >= (l1.a - l3.a) * (l2.b - l1.b);
}

Line allLines[N];
Line dq[N];


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
    for(int i = 0; i < n; ++i) allLines[i] = Line(eq[i].a[1], eq[i].a[0]);
    sort(allLines, allLines + n);
    int st = 0;
    int ed = 0;
    for(int i = 0; i < n; ++i) {
      if(ed >= 2 && removeConvexHull(dq[ed - 2], dq[ed - 1], allLines[i]));
      dq[ed++] = allLines[i];
    }
    for(int i = 0; i < q; ++i) {
      while(st + 1 < ed && dq[st].eval(que[i].t) >= dq[st + 1].eval(que[i].t)) st++;
      sol[que[i].idx] = dq[st].eval(que[i].t);
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