#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 5000;

const ll md = (ll)1e9 + 7LL;

ll cont[N];

inline ll addMod(ll a, ll b) {
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}

inline ll powMod(ll a, ll p) {
  ll sol = 1;
  while(p) {
    if(p & 1) sol = mulMod(sol, a);
    a = mulMod(a, a);
    p >>= 1;
  }
  return sol;
}

ll fat[N], invFat[N];

inline ll binomial(ll n, ll m) {
  if(m < 0) return 0;
  if(m == 0) return 1;
  ll foo = 1;
  for(int i = m + 1; i <= n; ++i) foo = mulMod(foo, i);
  return mulMod(foo, invFat[n - m]);
}

int n, m;
ll r[N];
ll allSum;

inline void main2() {
  scanf("%d %d", &n, &m);
  allSum = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%lld", r + i);
    allSum += r[i] * 2LL;
  }
  if(n == 1) {
    printf(" %d\n", m);
    return;
  }
  memset(cont, 0, sizeof cont);
  ll sol = 0;
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
    ll s = r[i] + r[j];
    int slots = m - 1 - (allSum - s);
    cont[r[i] + r[j]] += 2;
  }
  for(int i = 0; i < N; ++i) {
    if(cont[i]) {
      int slots = m - allSum + i - 1;
      sol = addMod(sol, mulMod(cont[i], binomial(n + slots, slots)));
    }
  }
  sol = mulMod(sol, fat[n - 2]);
  printf(" %lld\n", sol);
}

int main() {
  fat[0] = invFat[0] = 1;
  for(int i = 1; i < N; ++i) fat[i] = mulMod(i, fat[i - 1]), invFat[i] = powMod(fat[i], md - 2);
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}