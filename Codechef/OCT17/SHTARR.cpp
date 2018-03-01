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

#define pi acos(-1.0)

const int B = 200;
const int N = 1000001;

int n, q, a[N];
vi arrBlock[N];

inline void processBucket(int bk) {
  int s = (bk * B), e = ((bk + 1) * B) - 1;
  arrBlock[bk].clear();
  int sz = 0;
  for(int i = s; i <= e; ++i) {
    if(a[i] > sz) {
      arrBlock[bk].pb(a[i]);
      sz = a[i];
    }
  }
}

ii getInsideInterval(int st, int ed, int l, int r) {
  int qtd = 0;
  int sz = l - 1;
  for(int i = st; i <= min(ed, n - 1); ++i) {
    if(a[i] > sz) {
      qtd++;
      sz = a[i];
      if(sz >= r) break;
    }
  }
  return ii(qtd, sz);
}

int solve(int x, int l, int r) {
  int sol = 0;
  int sz = l - 1;
  if(x % B != 0) {
    int bk = x / B;
    ii foo = getInsideInterval(x, ((bk + 1) * B) - 1, l, r);
    sol = foo.F;
    sz = foo.S;
    x = ((bk + 1) * B);
  }
  while(x < n && sz < r) {
    int bk = x / B;
    vi :: iterator st = lower_bound(arrBlock[bk].begin(), arrBlock[bk].end(), sz + 1);
    vi :: iterator ed = lower_bound(arrBlock[bk].begin(), arrBlock[bk].end(), r);
    if(arrBlock[bk].end() != ed) {
      sz = *ed;
      sol += (ed - st + 1);
    }
    else sol += (ed - st);
    x = ((bk + 1) * B);
  }
  return sol;
}

inline void main2() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  for(int i = 0; i * B < n; ++i) processBucket(i);
  while(q--) {
    char op; scanf(" %c", &op);
    if(op == '?') {
      int i, l, r; scanf("%d %d %d", &i, &l, &r); i--;
      printf("%d\n", solve(i, l, r));
    }
    else {
      int i, x; scanf("%d %d", &i, &x); i--;
      a[i] += x;
      processBucket(i / B);
    }
  }
}


int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}