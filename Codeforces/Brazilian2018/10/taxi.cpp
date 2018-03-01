#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LINF 0x3f3f3f3f3f3f3f3f

struct Line {
  ll a, b;
  Line(){};
  Line(ll _a, ll _b) {
    a = _a;
    b = _b;
  }
  bool operator < (Line l) const {
    if(a != l.a) return a > l.a;
    return b < l.b;
  }
  ll eval(ll x) {
    return a * x + b;
  }
};

struct ConvexHullTrick {
  vector< Line > st;
  bool badLine(Line s, Line t, Line u) {
    return (t.b - s.b) * (s.a - u.a) >= (u.b - s.b) * (s.a - t.a);
  }
  void addLine(Line l) {
    while(st.size() >= 2 && badLine(st[st.size() - 2], st[st.size() - 1], l)) st.pop_back();
    st.push_back(l);
  }
  ll query(ll x) {
    if(st.size() == 0) return LINF;
    int lo = 0, hi = st.size() - 1;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(st[md].eval(x) <= st[md + 1].eval(x)) hi = md;
      else lo = md + 1;
    }
    return st[lo].eval(x);
  }
};

int main() {
  return 0;
}