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

const int N = 100010;
const int MAGIC = 40;
const int MOD = (ll)1e9;

inline ll addMod(int a, int b, int md = MOD) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

inline ll mulMod(int a, int b, int md = MOD) {
  return 1ll * a * b % md;
}

struct SegTree {
  int tr[4 * N], lz[4 * N];
  SegTree(){};
  void propagate(int no, int l, int r) {
    tr[no] += lz[no];
    if(l != r) {
      int nxt = (no << 1);
      lz[nxt] += lz[no];
      lz[nxt + 1] += lz[no];
    }
    lz[no] = 0;
  }
  void addRange(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return;
    if(l >= i && r <= j) {
      lz[no]++;
      propagate(no, l, r);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    addRange(nxt, l, mid, i, j);  addRange(nxt + 1, mid + 1, r, i, j);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
  void setPoint(int no, int l, int r, int i, int v) {
    propagate(no, l, r);
    if(l == r) {
      tr[no] = v;
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    if(i <= mid) setPoint(nxt, l, mid, i, v);
    else setPoint(nxt + 1, mid + 1, r, i, v);
    tr[no] = tr[nxt] + tr[nxt + 1];
  }
  int query(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return 0;
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return query(nxt, l, mid, i, j) + query(nxt + 1, mid + 1, r, i, j);
  }
};

void printVector(vector< int > v){
  for(int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

struct SpecialSegtree {
  vector< int > tr[4 * N];
  int lz[4 * N];
  SpecialSegtree() {
    for(int i = 0; i < 4 * N; ++i) tr[i].resize(MAGIC, 0);
  }
  void propagate(int no, int l, int r) {
    vector< int > sol(MAGIC, 0);
    for(int i = MAGIC - 1; i >= 0; --i) sol[(i + lz[no]) % MAGIC] = tr[no][i];
    for(int i = 0; i < min(MAGIC, lz[no]); ++i) sol[i] = 0;
    tr[no] = sol;
    if(l != r) {
      int nxt = (no << 1);
      lz[nxt] += lz[no];
      lz[nxt + 1] += lz[no];
    }
    lz[no] = 0;
  }
  vector< int > join(vector< int > a, vector< int > b) {
    vector< int > sol(MAGIC, 0);
    for(int i = 0; i < MAGIC; ++i) sol[i] = a[i] + b[i];
    return sol;
  }
  void addRange(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return;
    if(l >= i && r <= j) {
      lz[no]++;
      propagate(no, l, r);
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    addRange(nxt, l, mid, i, j);  addRange(nxt + 1, mid + 1, r, i, j);
    tr[no] = join(tr[nxt], tr[nxt + 1]);
  }

  void setPoint(int no, int l, int r, int i, int lstV, int atV) {
    propagate(no, l, r);
    if(lstV < MAGIC) tr[no][lstV]--;
    if(atV < MAGIC) tr[no][atV]++;
    if(l == r) return;
    int nxt = (no << 1), mid = (l + r) >> 1;
    if(i <= mid) setPoint(nxt, l, mid, i, lstV, atV);
    else setPoint(nxt + 1, mid + 1, r, i, lstV, atV);
  }

  void build(int no, int l, int r, int *a) {
    lz[no] = 0;
    if(l == r) {
      if(a[l] < MAGIC) tr[no][a[l]]++;
      return;
    }
    int nxt = (no << 1), mid = (l + r) >> 1;
    build(nxt, l, mid, a); build(nxt + 1, mid + 1, r, a);
    tr[no] = join(tr[nxt], tr[nxt + 1]);
  }
  vector< int > query(int no, int l, int r, int i, int j) {
    propagate(no, l, r);
    if(r < i || l > j) return vector<int>(MAGIC, 0);
    if(l >= i && r <= j) return tr[no];
    int nxt = (no << 1), mid = (l + r) >> 1;
    return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
  }
};

int n, m;
ll fat[MAGIC];
int a[N];
SegTree vet;
SpecialSegtree sp;

int main() {
  fat[0] = 1LL;
  for(int i = 1; i < MAGIC; ++i) {
    fat[i] = fat[i - 1] * i;
    fat[i] %= MOD;
  }

  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    vet.setPoint(1, 1, n, i, a[i]);
  }
  sp.build(1, 1, n, a);

  for(int i = 0; i < m; ++i) {
    int op, l, r; scanf("%d %d %d", &op, &l, &r);
    if(op == 1) {
      vet.addRange(1, 1, n, l, r);
      sp.addRange(1, 1, n, l, r);
    }
    else if(op == 2) {
      vector< int > foo = sp.query(1, 1, n, l, r);
      ll ans = 0;
      for(int i = 0; i < MAGIC; ++i) ans = addMod(ans, mulMod(foo[i], fat[i]));
      printf("%lld\n", ans);
    }
    else {
      int lstV = vet.query(1, 1, n, l, l);
      int atV = r;
      vet.setPoint(1, 1, n, l, atV);
      sp.setPoint(1, 1, n, l, lstV, atV);
    }
  }
  return 0;
}