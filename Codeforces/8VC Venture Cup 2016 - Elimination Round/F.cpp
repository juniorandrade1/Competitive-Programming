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

const int N = 201;
const int K = 1010;
const ll md = (ll)1e9 + 7;

inline  ll addMod(ll a, ll b) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

int a[N];
int n, k;
ll pd[N][N][K];

ll func(int pos, int openG, int qtd) {
  if(qtd > k) return 0;
  if(openG > n - pos) return 0;
  if(pos == n) return 1;
  if(pd[pos][openG][qtd] != -1) return pd[pos][openG][qtd];
  ll diff = a[pos];
  if(pos) diff -= a[pos - 1];
  ll ret = func(pos + 1, openG, qtd + openG * diff);
  ll aux = func(pos + 1, openG + 1, qtd + openG * diff);
  ret = addMod(ret, aux);
  aux = func(pos + 1, openG, qtd + openG * diff);
  aux = (aux * openG) % md;
  ret = addMod(ret, aux);
  if(openG) {
    aux = func(pos + 1, openG - 1, qtd + openG * diff);
    aux = (aux * openG) % md;
    ret = addMod(ret, aux);
  }
  return pd[pos][openG][qtd] = ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(0, 0, 0));
  return 0;
}