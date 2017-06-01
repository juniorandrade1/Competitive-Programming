#include <bits/stdc++.h>

using namespace std;

const int N = 4;

struct Time {
  int h, t, id;
  Time(){};
  void read(int _id) {
    scanf("%d %d", &h, &t);
    id = _id;
  }
  bool operator < (Time foo) const {
    if(h + t != foo.h + foo.t) return h + t < foo.h + foo.t;
    return id > foo.id;
  }
};

Time v[4];


int main() {
  for(int i = 0; i < 4; ++i) v[i].read(i);

  int s1, s2;
  s1 = s2 = 0;

  if(v[0] < v[1]) {
    s1 += v[0].t;
    v[0] = v[1];
  }
  else s1 += v[1].t;

  if(v[2] < v[3]) {
    s2 += v[2].t;
    v[1] = v[3];
  }
  else {
    s2 += v[3].t;
    v[1] = v[2];
  }
  v[0].t += s2;
  v[1].t += s1;

  //printf("-> %d %d\n", v[0].id + 1, v[1].id + 1);

  if(v[0] < v[1]) printf("%d\n", v[1].id + 1);
  else printf("%d\n", v[0].id + 1);
  return 0;
}