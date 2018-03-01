#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

struct Class {
  int qtd, idx;
  Class(){};
  Class(int _qtd, int _idx) {
    qtd = _qtd;
    idx = _idx;
  }
  bool operator < (Class other) {
    return qtd < other.qtd;
  }
};

struct Building {
  int cap, cost, idx;
  Building(){};
  Building(int _cap, int _cost, int _idx) {
    cap = _cap;
    cost = _cost;
    idx = _idx;
  }
  bool operator < (Building other) {
    if(cap != other.cap) return cap < other.cap;
    return cost < other.cost;
  }
};

int n, m;
int s[N], p[N], r[N];

Class c[N];
Building b[N];
multiset< pair<int, int> > all;
int sol[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%d", s + i);
  for(int i = 0; i < m; ++i) scanf("%d", p + i);
  for(int i = 0; i < m; ++i) scanf("%d", r + i);
  for(int i = 0; i < n; ++i) c[i] = Class(s[i], i);
  for(int i = 0; i < m; ++i) b[i] = Building(p[i], r[i], i);
  sort(c, c + n);
  sort(b, b + m);
  int j = m - 1;
  for(int i = n - 1; i >= 0; --i) {
    while(j >= 0 && b[j].cap >= c[i].qtd) all.insert(make_pair(b[j].cost, b[j].idx)), j--;
    if(all.size() == 0) {
      puts("impossible");
      return 0;
    }
    pair<int, int> foo = *all.begin();
    sol[c[i].idx] = foo.second;
    all.erase(all.begin());
  }
  for(int i = 0; i < n; ++i) {
    if(i) printf(" ");
    printf("%d", sol[i] + 1);
  }
  return 0;
}