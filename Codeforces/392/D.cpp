#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI acos(-1)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const ll LINF = (ll)1e18;

const int N = 100;

int n, m;
char s[N];
ll pd[N][N];
ll pw[N];

bool okMul(ll a, ll b) {
  if(a == 0) return 0;
  return b <= LINF / a;
}

bool okAdd(ll a, ll b) {
  return b < LINF - a;
}

ll func(int pos, int power) {
  if(power < 0) {
    if(pos == m) return 0;
    else return LINF;
  }
  if(pd[pos][power] != -1) return pd[pos][power];
  if(s[pos] == '0') {
    if(pos + 1 < m && s[pos + 1] == '0') return LINF;
    return pd[pos][power] = func(pos + 1, power - 1);
  }
  ll ret = LINF;
  ll at = 0;
  int aux =  pos;
  for(int i = pos; i < m; ++i) {
    at *= 10LL;
    at += s[i] - '0';
    if(at >= n) break;
    if(okMul(at, pw[power]) && okAdd(func(i + 1, power - 1), at * pw[power])) {
      ret = min(ret, func(i + 1, power - 1) + at * pw[power]);
    }
  }
  return pd[pos][power] = ret;
}

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  m = strlen(s);
  pw[0] = 1LL;
  int maxVal = 0;
  for(int i = 1;; ++i) {
    if(!okMul(pw[i - 1], n)) {
      maxVal = i;
      pw[i] = LINF;
      break;
    }
    else pw[i] = pw[i - 1] * (ll)n;
  }
  memset(pd, -1, sizeof pd);
  ll ans = LINF;
  for(int i = 0; i < maxVal; ++i) ans = min(ans, func(0, i));
  printf("%lld\n", ans);
  return 0;
}