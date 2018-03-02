#include <bits/stdc++.h>

using namespace std;

#define debug(x...) fprintf(stderr, x)

#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair< ll, ll > ii;

const int N = 2 * (int)1e5 + 10;

template <typename T> 
class ConvexHullTrick {
private:
  const T CHINF = numeric_limits<T>::max() / (T)2.0;
  struct Line {
    T m, b;
    Line(){};
    Line(T _m, T _b) {
      m = _m;
      b = _b;
    }
    bool operator < (Line other) const {
      if(m != other.m) return m > other.m;
      return b > other.b;
    }
    T getVal(T x) {
      return m * x + b;
    }
  };
public:
  vector< Line > st;
  bool badLine(Line s, Line t, Line u) {
    if(t.m == u.m) return true;
    return 1.0 * (t.b - s.b) * (s.m - u.m) >= 1.0 * (u.b - s.b) * (s.m - t.m); //don't forget 1.0
  }
  void addLine(T a, T b) {
    Line l = Line(a, b);
    while(st.size() >= 2 && badLine(st[st.size() - 2], st[st.size() - 1], l)) st.pop_back();
    st.push_back(l);
  }
  T query(T x) {
    if(st.size() == 0) return CHINF;
    int lo = 0, hi = st.size() - 1;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(-st[md + 1].m >= 2ll * x || st[md].getVal(x) <= st[md + 1].getVal(x)) hi = md;
      else lo = md + 1;
    }
    return st[lo].getVal(x);
  }
};

struct Edge {
  int x, y, b, e;
  Edge(){}; 
  Edge(int _x, int _y, int _b, int _e) {
    x = _x;
    y = _y;
    b = _b;
    e = _e;
  }
  bool operator < (Edge other) const {
    return e < other.e;
  }
};

int n, m;
vector< Edge > allEdges;
ConvexHullTrick< ll > ch[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i) {
    int x, y, b, e; scanf("%d %d %d %d", &x, &y, &b, &e); x--; y--;
    allEdges.push_back(Edge(x, y, b, e));
  }
  ch[0].addLine(0, 0);
  sort(allEdges.begin(), allEdges.end());
  ll ans = LINF;
  for(int i = 0; i < allEdges.size(); ++i) {
    int x = allEdges[i].x;
    int y = allEdges[i].y;
    int b = allEdges[i].b;
    int e = allEdges[i].e;
    ll sol = ch[x].query(b);
    sol += 1ll * b * b;
    if(y == n - 1) ans = min(ans, sol);
    ch[y].addLine(-2ll * e, 1ll * e * e + sol);
  }
  printf("%lld\n", ans);
  return 0;
}