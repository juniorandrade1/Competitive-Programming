#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Ev {
  ll s, d;
  Ev(){};
  void read() {
    scanf("%lld %lld", &s, &d);
  }
  bool operator < (Ev o) const {
    if(s != o.s) return s < o.s;
    return d < o.d;
  }
};

const int N = 100001;

int n;
Ev v[N];

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) v[i].read();
  sort(v, v + n);
  ll s = 0;
  for(int i = 0; i < n; ++i) {
    s = max(s, v[i].s);
    s += v[i].d;
  }
  printf("%lld\n", s);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}