#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll quad(ll x) {
  return x * x;
}

struct Circle {
  ll x, y, r;
  Circle(){};
  void read() {
    scanf("%lld %lld %lld", &x, &y, &r);
  }
  bool isInside(ll _x, ll _y) {
    return quad(x - _x) + quad(y - _y) <= quad(r);
  }
};

struct Event {
  int x, op;
  Event(){};
  Event(int _x, int _op) {
    x = _x;
    op = _op;
  }
  bool operator < (Event other) const {
    if(x != other.x) return x < other.x;
    return op < other.op;
  }
};

const int N = 1010;

int n, m, c, k; 
Circle agents[N];

ll go(int x) {
  vector< Event > ls;
  for(int i = 0; i < c; ++i) {
    ll dx = quad(x - agents[i].x);
    ll rr = quad(agents[i].r);
    if(dx > rr) continue;
    ll ry = rr - dx;
    ll d = sqrt(ry);
    ll yl = max((ll)1, agents[i].y - d);
    ll yr = min((ll)m, agents[i].y + d);
    ls.push_back(Event(yl, -1));
    ls.push_back(Event(yr, 1));
  }
  sort(ls.begin(), ls.end());
  ll ans = 0;
  int lstOk = 0;
  int qtd = 0;
  for(int i = 0; i < ls.size(); ++i) {
    if(ls[i].op == -1) {
      qtd++;
      if(qtd == k) lstOk = ls[i].x;
    }
    else {
      qtd--;
      if(qtd == k - 1) {
        ans += (ls[i].x - lstOk + 1);
      }
    }
  }
  return ans;
}

inline void main2() {
  scanf("%d %d %d %d", &n, &m, &c, &k);
  for(int i = 0; i < c; ++i) agents[i].read();
  ll ans = 0;
  for(int i = 1; i <= n; ++i) ans += go(i);
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}