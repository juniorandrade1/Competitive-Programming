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

const int N = 1e6 + 1;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int tr[4 * N];
int b[N];

int join(int x, int y) {
  if(x == -1) return y;
  if(y == -1) return x;
  if(b[x] > b[y]) return x;
  else return y;
}

void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = l;
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid);
  build(nxt + 1, mid + 1, r);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
}

int query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return -1;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

void update(int no, int l, int r, int i, int val) {
  if(l == r) {
    b[l] = val;
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, val);
  else update(nxt + 1, mid + 1, r, i, val);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
}

int n;
int v[N];

int lst[N];
int p[N];

int main() {
  arquivo();
  build(1, 0, N - 1);
  for(int i = 0; i < N; ++i) lst[i] = -1;

  scanf("%d", &n);

  int ans = 0;
  for(int i = 0; i < n; ++i) {

    scanf("%d", v + i);

    int b1, b2, b3;
    b1 = b2 = b3 = -1;
    if(v[i] >= 2) b1 = query(1, 0, N - 1, 0, v[i] - 2);
    if(v[i] <= N - 3) b2 = query(1, 0, N - 1,v[i] + 2, N - 1);
    b3 = query(1, 0, N - 1, v[i], v[i]);

    int v1, v2, v3;
    v1 = (b1 == -1) ? -1 : b[b1];
    v2 = (b2 == -1) ? -1 : b[b2];
    v3 = (b3 == -1) ? -1 : b[b3];

    if(v1 >= v2 && v1 >= v3) {
      p[i] = lst[b1];
      ans = max(ans, v1 + 1);
      update(1, 0, N - 1, v[i], v1 + 1);
    }
    else if(v2 >= v1 && v2 >= v3) {
      p[i] = lst[b2];
      ans = max(ans, v2 + 1);
      update(1, 0, N - 1, v[i], v2 + 1);
    }
    else {
      p[i] = lst[b3];
      ans = max(ans, v3 + 1);
      update(1, 0, N - 1, v[i], v3 + 1);
    }

    lst[v[i]] = i;
  }

  printf("%d\n", n - ans);
  vi sol;
  int idx = lst[query(1, 0, N - 1, 0, N - 1)];
  while(idx != -1)  {
    sol.pb(v[idx]);
    idx = p[idx];
  }
  reverse(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i) {
    printf("%lld ", sol[i]);
  }
  printf("\n");


  return 0;
}