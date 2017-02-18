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
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
}

const int N = 100500;
const int M = 300;

int n;
int v[N];
int in[N], out[N];
bitset<N / 2> arr;

struct est {
  int l, r;
  est() {};
  est(int _l, int _r) {
    l = _l;
    r = _r;
  }
  bool operator < (est other) const {
    if(r / M != other.r / M) return r / M < other.r / M;
    else return l < other.l;
  }
};

vector< est > query;

inline ll go(int x) {
  arr.flip(x);
  if(arr[x]) return 1;
  else return -1;
}

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 1; i <= 2 * n; ++i) {
    scanf("%d", v + i);
    if(in[v[i]] == 0) in[v[i]] = i;
    else out[v[i]] = i;
  }
  for(int i = 1; i <= n; ++i) query.pb(est(in[i], out[i]));
  sort(query.begin(), query.end());
  ll ans = 0;
  ll foo = 0;
  int l = 1, r = 0;
  for(int i = 0; i < query.size(); ++i) {
    int x = query[i].l, y = query[i].r;
    while(r < y) foo += go(v[++r]);
    while(r > y) foo += go(v[r--]);
    while(l < x) foo += go(v[l++]);
    while(l > x) foo += go(v[--l]);
    ans += foo;
  }
  printf("%lld\n", ans / 2LL);
  return 0;
}