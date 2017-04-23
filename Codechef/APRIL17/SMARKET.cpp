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

const int N = 1e5 + 10;

int v[N], Left[N], Right[N];
int n, q;

int L[40 * N], R[40 * N];
int tr[40 * N], root[40 * N], nodeCounter = 1;

void build(int no, int l, int r) {
  tr[no] = 0;
  if(l == r) return;
  L[no] = nodeCounter++;
  R[no] = nodeCounter++;
  int mid = (l + r) >> 1;
  build(L[no], l, mid);
  build(R[no], mid + 1, r);
}

int query(int noL, int noR, int l, int r, int i, int j) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[noR] - tr[noL];
  int mid = (l + r) >> 1;
  return query(L[noL], L[noR], l, mid, i, j) + query(R[noL], R[noR], mid + 1, r, i, j);
}

int update(int no, int l, int r, int i) {
  int newNode = nodeCounter++;
  tr[newNode] = tr[no] + 1;
  if(l == r) return newNode;
  L[newNode] = L[no];
  R[newNode] = R[no];
  int mid = (l + r) >> 1;
  if(i <= mid) L[newNode] = update(L[newNode], l, mid, i);
  else R[newNode] = update(R[newNode], mid + 1, r, i);
  return newNode;
}


inline void main2() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  Left[1] = 1;
  for(int i = 2; i <= n; ++i) {
    if(v[i] == v[i - 1]) Left[i] = Left[i - 1];
    else Left[i] = i;
  }
  Right[n] = n;
  for(int i = n - 1; i >= 1; --i) {
    if(v[i] == v[i + 1]) Right[i] = Right[i + 1];
    else Right[i] = i;
  }

  root[0] = 0;
  nodeCounter = 1;
  build(root[0], 0, n);
  for(int i = 1; i <= n; ++i) {
    if(Left[i] == i) root[i] = update(root[i - 1], 0, n, Right[i] - i + 1);
    else root[i] = root[i - 1];
  }
  while(q--) {
    int l, r, k; scanf("%d %d %d", &l, &r, &k);
    if(Right[l] >= r) {
      int ans = (r - l + 1 >= k);
      printf("%d\n", ans);
    }
    else {
      int ans = (Right[l] - l + 1 >= k) + (r - Left[r] + 1 >= k);
      if(Right[l] + 1 <= Left[r] - 1) {
        int lf = Right[l] + 1;
        int rg = Left[r] - 1;
        ans += query(root[lf - 1], root[rg], 0, n, k, n);
      }
      printf("%d\n", ans);
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
