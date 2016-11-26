#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

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
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 5000101;

int is[N];

void crivo() {
  is[1] = 1;
  is[0] = 0;
  for(int i = 2; i < N; ++i) {
    if(is[i] == 0) {
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
}

int v[N];
int tr[4 * N];

void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = is[v[l]];
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
  tr[no] = max(tr[nxt], tr[nxt + 1]);
}

int query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return max(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

int n, m;

inline void go() {
  for(int i = 0; i < n / 2; ++i) {
    v[i] += v[n - i - 1];
  }
  n = (n + 1) / 2;
  build(1, 0, n - 1);
}

int main() {
  crivo();
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  build(1, 0, n - 1);
  while(m--) {
    int op; scanf("%d", &op);
    if(op == 1) go();
    else {
      int l, r; scanf("%d %d", &l, &r);
      l--;r--;
      printf("%d\n", query(1, 0, n - 1, l, r));
    }
  }
  return 0;
}