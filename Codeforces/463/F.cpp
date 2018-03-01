#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

const double is_query = -HUGE_VAL;

struct Line {
  double m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    double x = rhs.m;
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
  void insert_line(double m, double b) {
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  double eval(double x) {
    auto l = *lower_bound((Line) { x, is_query });
    return l.m * x + l.b;
  }
};

HullDynamic ch[N];
int n;
ll a[N], b[N], m[N];
ll dp[N];
vector< int > g[N];

void dfs(int x, int ult) {
  m[x] = x;
  int idx = -1, big = -1, qtd = 0;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
    qtd++;
    if((int)ch[m[y]].size() > big) {
      big = ch[m[y]].size();
      idx = m[y];
    }
  }
  if(qtd == 0) {
    ch[m[x]].insert_line(-b[x], -dp[x]);
    return;
  }
  else {
    m[x] = idx;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i];
      if(y == ult) continue;
      if(m[x] == m[y]) continue;
      for(multiset< Line > :: iterator it = ch[m[y]].begin(); it != ch[m[y]].end(); it++) {
        ch[m[x]].insert_line(it->m, it->b);
      } 
      ch[m[y]].clear();
    }
    dp[x] = round(-ch[m[x]].eval(a[x]));
    ch[m[x]].insert_line(-b[x], -dp[x]);
    
    return;
  } 
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
  for(int i = 1; i <= n; ++i) scanf("%lld", b + i);
  for(int i = 1; i + 1 <= n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 1);
  for(int i = 1; i <= n; ++i) {
    if(i != 1) printf(" ");
    printf("%lld", dp[i]);
  }
  printf("\n");
  return 0;
}