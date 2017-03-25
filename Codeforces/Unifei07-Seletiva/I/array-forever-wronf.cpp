#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
#define pi acos(-1.0)
#define eps 1e-6

const int N = 50010;
const int M = 5150;

int is[N], p[N], sz = 0, idx[N];

inline void crivo() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      idx[i] = sz;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
}

struct BIT{
  int bit[N];
  BIT(){};
  void add(int x, int val) {
    while(x < N) {
      bit[x] += val;
      x += LSONE(x);
    }
  }
  int query(int x) {
    int ret = 0;
    while(x) {
      ret += bit[x];
      x -= LSONE(x);
    }
    return ret;
  }
  int rangeQuery(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int n;
BIT b[M];
int v[N];

inline void go(int pos, int val) {
  set<int>s;
  int x = v[pos];
  while(x != 1) {
    s.insert(is[x]);
    x /= is[x];
  }
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) b[idx[*it]].add(pos, val);
}

int main() {
  crivo();
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    go(i, 1);
  }
  int q; scanf("%d", &q);
  int lstAns = 0;
  while(q--) {
    int op, l, r; scanf("%d %d %d", &op, &l, &r);
    if(op == 0) {
      int sol = 1;
      for(int i = 0; i < M; ++i) sol = max(sol, b[i].rangeQuery(l, r));
      printf("%d\n", sol ^ lstAns);
      lstAns = (sol ^ lstAns);
    }
    else {
      go(l, -1);
      v[l] = r;
      go(l, 1);
    }
  }
  return 0;
}