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

const int N = 2 * (1e5 + 10);
const int M = 2400;

int arr[N], n, q;

inline void printArray() {
  debug("arr = {");
  for(int i = 1; i <= n; ++i) {
    debug(" %d", arr[i]);
  }
  debug(" }\n");
}

struct BIT {
  int bit[N];
  void update(int x, int val) {
    while(x < N) {
      bit[x] += val;
      x += LSONE(x);
    }
  }
  ll query(int x) {
    ll ret = 0;
    while(x) {
      ret += bit[x];
      x -= LSONE(x);
    }
    return ret;
  }
};

BIT aux[(N + M - 1) / M];

ll query(int l, int r, int x) {
   int bL = l / M;
   int bR = r / M;
   ll res = 0;
   if(bL == bR) {
    for(int i = l; i <= r; ++i) res += arr[i] < x;
  }
   else {
    for(int i = bL + 1; i < bR; ++i) res += aux[i].query(x);
    for(int i = l; i < ((bL + 1) * M); ++i) res += arr[i] < x;
    for(int i = (bR * M); i <= r; ++i) res += arr[i] < x;
   }
   return res;
}

ll go(int l, int r) {
  if(l == r) return 0;
  if(l + 1 == r) return (arr[l] < arr[r] ? 1 : -1);
  ll ans = (arr[l] < arr[r] ? 1 : -1);

  int nL = l + 1;
  int nR = r - 1;

  ll countLMenor, countLMaior;

  countLMenor = query(nL, nR,arr[l]);
  countLMaior = (nR - nL + 1) - countLMenor;

  ans += countLMaior - countLMenor;

  countLMenor = query(nL, nR, arr[r]);
  countLMaior = (nR - nL + 1) - countLMenor;

  ans += countLMenor - countLMaior;


  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    aux[i / M].update(i, 1);
    arr[i] = i;
  }
  ll ans = 0;
  for(int i = 0; i < q; ++i) {
    int l, r; scanf("%d %d", &l, &r);
    if(r < l) swap(l, r);
    ans += go(l, r);
    printf("%lld\n", ans);
    aux[l / M].update(arr[l], -1);
    aux[r / M].update(arr[r], -1);
    swap(arr[l], arr[r]);
    aux[l / M].update(arr[l], 1);
    aux[r / M].update(arr[r], 1);
  }
  return 0;
}