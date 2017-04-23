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

const ll MOD = 1000000007;

inline int addMod(ll a, ll b) {
  a += b;
  if(a >= MOD) a -= MOD;
  return a;
}

inline int mulMod(ll a, ll b) {
  return (a * b) % MOD;
}


const int N = 100001;
const int M = 2;

struct Matrix {
  int m[M][M];
  Matrix() {
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
  }
  Matrix(int x) {
    if(x == -INF) for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) m[i][j] = (i == j);
    else for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) m[i][j] = x;
  }
  Matrix operator * (const Matrix &other) {
    Matrix s;
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) {
      s.m[i][j] = 0;
      for(int k = 0; k < M; ++k) s.m[i][j] = addMod(s.m[i][j], mulMod(m[i][k], other.m[k][j]));
    }
    return s;
  }
  Matrix operator *= (const Matrix &other) {
    Matrix s;
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) {
      s.m[i][j] = 0;
      for(int k = 0; k < M; ++k) s.m[i][j] = addMod(s.m[i][j], mulMod(m[i][k], other.m[k][j]));
    }
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) m[i][j] = s.m[i][j];
  }
  Matrix operator + (const Matrix &other) {
    Matrix a;
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) a.m[i][j] = addMod(m[i][j], other.m[i][j]);
    return a;
  }
};

Matrix matrixPower(Matrix m, ll p) {
  Matrix s = Matrix(-INF);
  while(p) {
    if(p & 1) s = s * m;
    p >>= 1;
    m = m * m;
  }
  return s;
}

Matrix IDENTITY = Matrix(-INF);

int n;
int v[N];
Matrix tr[4 * N];
Matrix lz[4 * N];
bitset<4 * N> changed;

inline void propagate(int no, int l, int r) {
  if(l != r) {
    int nxt = (no << 1);
    lz[nxt] *= lz[no];
    lz[nxt + 1] *= lz[no];
    changed[nxt] = changed[nxt + 1] = 1;
  }
  tr[no] *= matrixPower(lz[no], (r - l + 1));
  lz[no] = Matrix(-INF);
  changed[no] = 0;
}

void build(int no, int l, int r) {
  lz[no] = Matrix(-INF);
  changed[no] = 0;
  if(l == r) {
    tr[no] = matrixPower(tr[no], v[l]);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

int query(int no, int l, int r, int i, int j) {
  if(changed[no]) propagate(no, l, r);
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no].m[0][0];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return addMod(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

Matrix poweredUpdate[101];

void update(int no, int l, int r, int i, int j, int d) {
  if(changed[no]) propagate(no, l, r);
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    lz[no] = poweredUpdate[d];
    changed[no] = 1;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  update(nxt, l, mid, i, j, d); update(nxt + 1, mid + 1, r, i, j, d);
  tr[no] = tr[nxt] + tr[nxt + 1];
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  build(1, 0, n - 1);
  int q; scanf("%d", &q);
  while(q--) {
    int op, l, r; scanf("%d %d %d", &op, &l, &r);
    l--; r--;
    if(op == 1) {
      printf("%d\n", query(1, 0, n - 1, l, r));
    }
    else {
      int d; scanf("%d", &d);
      update(1, 0, n - 1, l, r, d);
    }
  }
}

int main() {
  for(int i = 0; i <= 100; ++i) poweredUpdate[i] = matrixPower(Matrix(), i);
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}