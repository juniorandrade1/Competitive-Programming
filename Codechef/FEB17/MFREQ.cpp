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
#define PI acos(-1.0)
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
const int N = 100010;
 
struct node {
  int maxEsq, valueEsq;
  int maxDir, valueDir;
  int maxAll, value;
  int len;
  node(){
    maxEsq = maxDir = maxAll = value = valueEsq = valueDir = -1;
    len = 0;
  }
  node(int _a, int _b, int _c, int _d, int _e, int _f)  {
    maxEsq = _a;
    valueEsq = _b;
    maxDir = _c;
    valueDir = _d;
    maxAll = _e;
    value = _f;
    len = 1;
  }
  node(int _a, int _b, int _c, int _d, int _e, int _f, int _g)  {
    maxEsq = _a;
    valueEsq = _b;
    maxDir = _c;
    valueDir = _d;
    maxAll = _e;
    value = _f;
    len = _g;
  }
};
 
node tr[4 * N];
int n, m;
int v[N];
 
node join(node a, node b) {
  int pp = -1;
  int vv = -1;
  if(a.valueDir == b.valueEsq) {
    int sumDirEsq = a.maxDir + b.maxEsq;
    if(sumDirEsq > vv) {
      vv = sumDirEsq;
      pp = a.valueDir;
    }
  }
  if(a.maxEsq > vv) {
    vv = a.maxEsq;
    pp = a.valueEsq;
  }
  if(b.maxEsq > vv) {
    vv = b.maxEsq;
    pp = b.valueEsq;
  }
  if(a.maxDir > vv) {
    vv = a.maxDir;
    pp = a.maxDir;
  }
  if(b.maxDir > vv) {
    vv = b.maxDir;
    pp = b.valueDir;
  }
 
  int qtdEsq = (a.len == a.maxEsq && a.valueEsq == b.valueEsq) ? a.maxEsq + b.maxEsq : a.maxEsq;
  int qtdDir = (b.len == b.maxDir && a.valueDir == b.valueDir) ? b.maxDir + a.maxDir : b.maxDir;
 
  if(qtdEsq > vv) {
    vv = qtdEsq;
    pp = a.valueEsq;
  }
  if(qtdDir > vv) {
    vv = qtdDir;
    pp = b.valueDir;
  }
 
  if(a.maxAll > vv) {
    vv = a.maxAll;
    pp = a.value;
  }
 
  if(b.maxAll > vv) {
    vv = b.maxAll;
    pp = b.value;
  }
 
  return node(qtdEsq, a.valueEsq, qtdDir, b.valueDir, vv, pp, a.len + b.len);
}
 
void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = node(1, v[l], 1, v[r], 1, v[l], 1);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
}
 
node query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return node();
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}
 
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  build(1, 1, n);
  for(int i = 0; i < m; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    node foo = query(1, 1, n, a, b);
    if(foo.maxAll >= c) printf("%d\n", foo.value);
    else puts("-1");
  }
  return 0;
} 