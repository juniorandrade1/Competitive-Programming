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

const int N = 3;

const ll md = (ll)1e9 + 7LL;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md; 
}

struct Matrix { 
  ll mat[N][N]; 
  Matrix() {
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) mat[i][j] = i * 3 + j + 1;
  }
};

Matrix matMul(Matrix a, Matrix b) {
  Matrix ans; int i, j, k;
  for (i = 0; i < N; i++) for (j = 0; j < N; j++) for (ans.mat[i][j] = k = 0; k < N; k++) ans.mat[i][j] = addMod(ans.mat[i][j], mulMod(a.mat[i][k], b.mat[k][j]));
  return ans;
}

Matrix matPow(Matrix base, ll p) {
  Matrix ans; int i, j;
  for (i = 0; i < N; i++) for (j = 0; j < N; j++)
  ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}

ll sol(ll x) {
  Matrix mat;
  mat = matPow(mat, x - 1);
  ll ans = 0;
  for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) ans = addMod(ans, mat.mat[i][j]);
  return ans;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    ll x; scanf("%lld", &x);
    printf("%lld\n", sol(x));
  }
  return 0;
}