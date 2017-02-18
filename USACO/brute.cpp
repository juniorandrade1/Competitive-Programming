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
  freopen("mincross.in", "r", stdin);
  freopen("mincross.out", "w", stdout);
}

const int N = 200010;

/*
int root[5 * N], tr[5 * N], L[5 * N], R[5 * N];
int countSeg = 1;

void build(int no, int l, int r) {
  tr[no] = 0;
  if(l == r) return;
  int mid = (l + r) >> 1;
  L[no] = countSeg++;
  R[no] = countSeg++;
  build(L[no], l, mid);
  build(R[no], mid + 1, r);
}

int update(int no, int l, int r, int i, int val) {
  int NO = countSeg++;
  tr[NO] = tr[no] + val;
  L[NO] = L[no];
  R[no] = R[no];
  if(l == r) return NO;
  int mid = (l + r) >> 1;
  if(i <= mid) L[NO] = update(L[NO], l, mid, i, val);
  else R[NO] = update(R[NO], mid + 1, r, i, val);
  return NO;
}
*/

struct BIT {
  int bit[N];
  BIT(){
    memset(bit, 0, sizeof bit);
  }
  void add(int x,  int val) {
    x += 2;
    while(x < N) {
      bit[x] += val;
      x += LSONE(x);
    }
  }
  
  ll query(int x) {
    x += 2;
    int ret = 0;
    while(x) {
      ret += bit[x];
      x -= LSONE(x);
    }
    return ret;
  }
};

int n;
int a[N], b[N], rb[N];
BIT b1;


int main() {
  arquivo(); 
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i + n] = a[i];
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    rb[b[i]] = i;
  }
  ll ans = LINF;
  for(int i = 1; i <= n; ++i) {
    ll sol = 0;
    b1 = BIT();
    for(int j = 0; j < n; ++j) {
      int x = a[i + j];
      b1.add(rb[x], 1);
      sol += b1.query(n) - b1.query(rb[x]);
    }
    ans = min(ans, sol);
  }
  printf("%lld\n", ans);
  return 0;
}