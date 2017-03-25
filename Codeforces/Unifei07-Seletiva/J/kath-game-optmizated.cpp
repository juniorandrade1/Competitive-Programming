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

const int N = 4000000;

int tr[N];
int L[N], R[N], root[N];
int new_idx;
int n, m;
 
void build(int no, int l, int r) {
  tr[no] = 0;
  if( l == r ) return;
  L[no] = new_idx++;
  R[no] = new_idx++;
  int mid = (l+r)>>1;
  build(L[no],l,mid); build(R[no],mid+1,r);
}
 
 
int upd( int no, int l, int r, int pos ) {
  int id = new_idx++;
  tr[id] = tr[no]+1;
  if( l == r ) return id;
  L[id] = L[no];
  R[id] = R[no];
  int mid = (l+r)>>1;
  if( pos <= mid ) L[id] = upd(L[id],l,mid,pos);
  else R[id] = upd(R[id],mid+1,r,pos);
  return id;
}
 
int query( int nol, int nor, int l, int r, int i, int j ) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[nor] - tr[nol];
  int mid = (l + r) >> 1;
  return query(L[nol],L[nor],l,mid,i, j) + query(R[nol],R[nor],mid+1,r,i,j);
}

int v[N];
set<int>s;
map<int, int>idx;
int countIdx = 0;

inline int queryUp(int l, int r, int y) {
  if(s.lower_bound(y) == s.end()) return 0;
  int numero = *s.lower_bound(y);
  return query(root[l - 1], root[r], 0, n, idx[numero], n);
}

const int M = 80;

double dp[M][M][2 * M];

inline double solve(int a, int b, int z) {
  double ans = 0;
  double qtd = 0;
  for(int i = 0; i <= a; ++i) {
    for(int j = 0; j < 2 * M; ++j) {
      ans += dp[i][z - i][j];
      qtd++;
    }
  }
  return ans;
}

inline void preCalc() {
  for(int i = 0; i < M; ++i) {
    for(int j = 0; j < M; ++j) {
      for(int k = 0; k < 2 * M; ++k) {
        dp[i][j][k] = 0.0;
        if(i == 0 && j == 0 && k <= M) dp[i][j][k] = (k > M) ? 1.0 : 0.0;
        else if(i && j) {
          dp[i][j][k] = (i * dp[i - 1][j][k - 1] + dp[i][j - 1][k + 1] * j) / (i + j);
        }
        else if(i) {
          if(k) dp[i][j][k] = dp[i - 1][j][k - 1];
        }
        else {
          if(k + 1 < 2 * M) dp[i][j][k] = dp[i][j - 1][k + 1];
        }
      }
    }
  }


  //for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) for(int k = 2 * M - 2; k >= 0; --k) dp[i][j][k] += dp[i][j][k + 1];
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i), s.insert(v[i]);
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) idx[*it] = countIdx++;
  new_idx = 1;
  build(root[0] = 0, 0, n);
  for(int i = 1; i <= n; ++i) root[i] = upd(root[i - 1], 0, n, idx[v[i]]);
  preCalc();
  scanf("%d", &m);
  while(m--) {
    int l, r, y, z;
    scanf("%d %d %d %d", &l, &r, &y, &z);
    int qUp = queryUp(l, r, y);
    int qDown = (r - l + 1) - qUp;
    //debug("%d %d\n", qUp, qDown);
    printf("%.10lf\n", solve(qUp, qDown, z));
  }
  return 0;
}