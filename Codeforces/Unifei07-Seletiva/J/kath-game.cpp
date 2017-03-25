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

const int N = 5000000;

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
 
 
int upd(int no, int l, int r, int pos ) {
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

const int M = 81;

double dp[M][M][M][2 * M];
bitset<M>memo[M][M][2 * M];

double calcProb(int a, int b, int z, int gap) {
  if(gap < 0) return 0.0;
  if(gap >= 2 * M) return 1.0;
  if(z == 0) return gap > M;
  if(memo[a][b][z][gap]) return dp[a][b][z][gap];
  double ret = 0;
  if(a && b) ret = (calcProb(a - 1, b, z - 1, gap + 1) * a + calcProb(a, b - 1, z - 1, gap - 1) * b) / (a + b);
  else if(a) ret = calcProb(a - 1, b, z - 1, gap + 1);
  else ret = calcProb(a, b - 1, z - 1, gap - 1);
  memo[a][b][z][gap] = 1;
  return dp[a][b][z][gap] = ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i), s.insert(v[i]);
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) idx[*it] = countIdx++;
  new_idx = 1;
  build(root[0] = 0, 0, n);
  for(int i = 1; i <= n; ++i) root[i] = upd(root[i - 1], 0, n, idx[v[i]]);
  scanf("%d", &m);
  while(m--) {
    int l, r, y, z;
    scanf("%d %d %d %d", &l, &r, &y, &z);
    int qUp = queryUp(l, r, y);
    int qDown = (r - l + 1) - qUp;
    printf("%.10lf\n", calcProb(qUp, qDown, z, M));
  }
  return 0;
}