#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

struct ev {
  int x, y0, y1, t;
  ev(){};
  ev(int _x, int _y0, int _y1, int _t) {
    x = _x;
    y0 = _y0;
    y1 = _y1;
    t = _t;
  }
  bool operator < (ev other) {
    if(x != other.x ) return x < other.x;
    return t > other.t;
  }
};

vector< ev > ls;
int c[N];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x0, y0, x1, y1; scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    y0 += 5005;
    y1 += 5005;
    ls.push_back(ev(x0, y0, y1, 1));
    ls.push_back(ev(x1, y0, y1, -1));
  }
  int ans = 0;
  int qtd = 0;
  int lst = 0;
  sort(ls.begin(), ls.end());
  for(int i = 0; i < ls.size(); ++i) {
    if(qtd == n) {
      int d = ls[i].x - lst;
      int q = 0;
      for(int i = 1; i < N; ++i) {
        c[i] += c[i - 1];
        q += (c[i] == n);
      }
      printf("%lld\n", 1ll * q * d);
      return 0;
    }
    qtd += ls[i].t;
    c[ls[i].y0] += ls[i].t;
    c[ls[i].y1] -= ls[i].t;
    lst = ls[i].x;
  }
  printf("0\n");
  return 0;
}