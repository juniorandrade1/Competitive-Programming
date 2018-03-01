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

const int N = 50;

bool overflow(ull a, ull b) {
  return ULLONG_MAX - a < b;
}

int n, k;
ull v[N];
ull la, lb;
vector< ull > all[N];

ll getSol(ull s, int q) {
  int p = k - q;
  if(s > lb) return 0;
  ull lwb = (s > la) ? 0 : (la - s);
  ull uwb = lb - s;
  ll sol = upper_bound(all[p].begin(), all[p].end(), uwb) - lower_bound(all[p].begin(), all[p].end(), lwb);
  return sol;
}

inline void main2() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < N; ++i) all[i].clear();
  for(int i = 0; i < n; ++i) scanf("%llu", v + i);
  scanf("%llu %llu", &la, &lb);
  sort(v, v + n);
  if(n == 1) {
    int ans = 0;
    ans += (v[0] >= la && v[0] <= lb);
    ans += (0 >= la && 0 <= lb);
    printf("%d\n", ans);
    return;
  }
  int nd = n / 2;
  for(int i = 0; i < (1 << nd); ++i) {
    int sum = 0;
    int qtd = 0;
    for(int j = 0; j < nd; ++j) if((i >> j) & 1) {
      sum += v[j];
      qtd++;
    }
    all[qtd].pb(sum);
  }
  for(int i = 0; i < N; ++i) sort(all[i].begin(), all[i].end());
  ll ans = 0;
  for(int i = nd; i < n; ++i) v[i - nd] = v[i];
  nd = n - nd;
  for(int i = 0; i < (1 << nd); ++i) {
    ull sum = 0;
    int qtd = 0;
    for(int j = 0; j < nd; ++j) if((i >> j) & 1) {
      if(overflow(sum, v[j])) {
        qtd = INF;
        break;
      }
      sum += v[j];
      qtd++;
    }
    if(qtd > k) continue;
    ll foo = getSol(sum, qtd);
    ans += foo;
  }
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}