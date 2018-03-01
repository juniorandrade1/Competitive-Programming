#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const int M = 2020;

typedef long long ll;

struct item {
  ll t, d, p;
  int id;
  item(){};
  void read(int _id) {
    scanf("%lld %lld %lld", &t, &d, &p);
    id = _id;
  }
  bool operator < (item other) const {
    if(d != other.d) return d < other.d;
    return t < other.t;
  }
};

item all[N];
int n;
ll pd[N][M];

ll func(int pos, int tmp) {
  if(pos == n) return 0;
  if(pd[pos][tmp] != -1) return pd[pos][tmp];
  ll ret = func(pos + 1, tmp);
  if(tmp + all[pos].t < all[pos].d) ret = max(ret, func(pos + 1, tmp + all[pos].t) + all[pos].p);
  return pd[pos][tmp] = ret;
}

vector<int>solution;

void back(int pos, int tmp) {
  if(pos == n) return;
  ll foo = pd[pos][tmp];
  if(foo == func(pos + 1, tmp)) back(pos + 1, tmp);
  else  {
    solution.push_back(all[pos].id);
    back(pos + 1, tmp + all[pos].t);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) all[i].read(i);
  sort(all, all + n);
  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(0, 0));
  back(0, 0);
  printf("%d\n", (int)solution.size());
  for(int i = 0; i < (int)solution.size(); ++i) {
    if(i) printf(" ");
    printf("%d", solution[i] + 1);
  }
  printf("\n");
  return 0;
}