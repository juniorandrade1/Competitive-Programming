#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

struct Event {
  int x, id, type;
  Event(){};
  Event(int _x, int _id, int _type) {
    x = _x;
    id = _id;
    type = _type;
  }
  bool operator < (Event ev) {
    if(x != ev.x) return x < ev.x;
    return type < ev.type;
  }
};

int n, q;
vector< Event > ls;
bitset< N > sol[N];

inline void process() {
  sort(ls.begin(), ls.end());
  bitset< N > foo;
  for(int i = 0; i < ls.size(); ++i) {
    if(ls[i].type == 1) sol[ls[i].id] ^= foo;
    else foo.flip(ls[i].id);
  }
}

inline void main2(int test) {
  ls.clear();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int l, r; scanf("%d %d", &l, &r);
    ls.push_back(Event(l, i, 0));
    ls.push_back(Event(r, i, 2));
  }
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    sol[i].reset();
    int m; scanf("%d", &m);
    for(int j = 0; j < m; ++j) {
      int x; scanf("%d", &x);
      ls.push_back(Event(x, i, 1));
    }
  }
  process();
  for(int i = 0; i < q; ++i) {
    printf("%d\n", sol[i].count());
  }
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) main2(tt);
  return 0;
}