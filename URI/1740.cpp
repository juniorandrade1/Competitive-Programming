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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 10010;

struct node {
  bool eq, inc, dec;
  node(){
    eq = inc = dec = false;
  };
  node(bool _eq, bool _inc, bool _dec) {
    eq = _eq;
    inc = _inc;
    dec = _dec;
  }
};

int v[N];
int n;
node tr[4 * N];

inline node join(int no, int l, int r) {
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(tr[nxt].eq && tr[nxt + 1].eq && v[mid] == v[mid + 1]) return node(1, 0, 0);
  if(tr[nxt].inc && tr[nxt + 1].inc && v[mid] < v[mid + 1]) return node(0, 1, 0);
  if(tr[nxt].dec && tr[nxt + 1].dec && v[mid] > v[mid + 1]) return node(0, 0, 1);
  return node();
}

void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = node(1, 1, 1);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
  tr[no] = join(no, l, r);
}

void update(int no, int l, int r, int i) {
  if(l == r) {
    tr[no] = node(1, 1, 1);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i);
  else update(nxt + 1, mid + 1, r, i);
  tr[no] = join(no, l, r);
}

int main() {
  //arquivo();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  build(1, 0, n - 1);
  
 
  return 0;
}