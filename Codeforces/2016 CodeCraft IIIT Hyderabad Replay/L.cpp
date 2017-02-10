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
#define eps 1e-6

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const ll md = (ll)1e9 + 7LL;

const int N = 150;
int n, m, k;

inline ll addMod(ll a, ll b, ll MOD = md) {
  a += b;
  while(a >= MOD) a -= MOD;
  return a;
}

inline ll mulMod(ll a, ll b, ll MOD = md) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

struct Matrix {
  ll graph[N][N], qtd[N][N];
  Matrix(){ 
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
      this->graph[i][j] = LINF;
      this->qtd[i][j] = 0;
    }
  }

  Matrix operator * (Matrix other) {
    Matrix sol;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        for(int k = 0; k < n; ++k) if(qtd[i][k] && other.qtd[k][j]) sol.graph[i][j] = min(sol.graph[i][j], graph[i][k] + other.graph[k][j]);
        for(int k = 0; k < n; ++k) if(sol.graph[i][j] == graph[i][k] + other.graph[k][j]) sol.qtd[i][j] = addMod(sol.qtd[i][j], mulMod(qtd[i][k], other.qtd[k][j]));
      }
    }
    return sol;
  }
};

Matrix powModMatrix(Matrix mat, ll power) {
  Matrix ret;

  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) mat.qtd[i][j] = (mat.graph[i][j] != 0);
  
  for(int i = 0; i < n; ++i) {
    ret.graph[i][i] = 0;
    ret.qtd[i][i] = 1;
  }

  while(power) {
    if(power & 1) ret = ret * mat;
    mat = mat * mat;
    power >>= 1;
  }
  return ret;
}


Matrix mat;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y); x--; y--;
    ll w; scanf("%lld", &w);
    mat.graph[x][y] = mat.graph[y][x] = w;
  }
  mat = powModMatrix(mat, k);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(mat.graph[i][j] == LINF) printf("X 0 ");
      else printf("%lld %lld ", mat.graph[i][j], mat.qtd[i][j]);
    }
    printf("\n");
  }
  return 0;
}