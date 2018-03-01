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

const int N = 55;

int n, k;
ull v[N];
ull s[N];
ull c[N][N];

inline ll solve(ull mx) {
  ll ans = 0;
  int qtd = k;
  for(int i = n - 1; i >= 0; --i) {
    if(v[i] > mx) continue;
    if(qtd >= 0) ans += c[i][qtd];
    qtd--;
    mx -= v[i];
  }
  return ans + (qtd == 0);
}

inline void main2() {
  c[0][0] = 1;
  for(int i = 1; i < N; ++i) for(int j = 0; j <= i; ++j) if(j == 0 || j == i) c[i][j] = 1; else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%llu", v + i);
  sort(v, v + n);
  ull a, b; scanf("%llu %llu", &a, &b);
  printf("%lld\n", solve(b) - ((a > 0) ? solve(a - 1) : solve(a)));
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}