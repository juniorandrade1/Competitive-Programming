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
  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);
}

const int N = 1010;

int a[N], b[N];
int ra[N], rb[N];
int n;

int pd[N][N];

int func(int l, int r) {
  if(l == n + 1) return 0;
  if(pd[l][r] != -1) return pd[l][r];
  int ret = func(l + 1, r);
  int x = a[l];
  for(int i = max(1, x - 4); i <= min(n, x + 4); ++i) {
    if(rb[i] >= r) ret = max(ret, 1 + func(l + 1, rb[i] + 1));
  }
  return pd[l][r] = ret;
}

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ra[a[i]] = i;
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    rb[b[i]] = i;
  }
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(1, 1));
  return 0;
}