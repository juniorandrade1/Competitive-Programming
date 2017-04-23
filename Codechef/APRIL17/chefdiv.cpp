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
 
const int N = 1e6 + 10;
 
ll p[N], sz = 0;
int is[N];
 
inline ll solve(ll x) {
  if(x == 1) return 0;
  vi f;
  for(int i = 0; i < sz && x >= N; ++i) {
    if(x < p[i] * p[i]) break;
    while(x % p[i] == 0) {
      f.pb(p[i]);
      x /= p[i];
    }
  }
  if(x < N) {
    while(x > 1) {
      f.pb(is[x]);
      x /= is[x];
    }
  }
  if(x > 1) {
    f.pb(x);
    x = 1;
  }
  sort(f.begin(), f.end());
  pq<ll>t;
  ll ans = 0;
  ll at = 1;
  for(int i = 0; i < f.size(); ++i) {
    int j = i;
    while(f[i] == f[j] && j < f.size()) j++;
    t.push(j - i);
    at *= (j - i + 1);
    i = j - 1;
  }
  ans += (at - 1);
  while(!t.empty()) {
    ll foo = t.top(); t.pop();
    at /= (foo + 1);
    foo--;
    at *= (foo + 1);
    ans += at;
    if(foo) t.push(foo);
  }
  return ans;
}
 
inline void crivo() {
  for(int i = 2; i < N; ++i) {
    if(is[i] == 0) {
      p[sz++] = i;
      is[i] = i;
    }
    for(int j = 0; j < sz && p[j] <= is[i] && i * p[j] < N; ++j) is[i * p[j]] = p[j] ;
  }
}
 
int main() {
  crivo();
  ll a, b;
  scanf("%lld %lld", &a, &b);
  ll rsp = 0;
  for(ll i = a; i <= b; ++i) rsp += solve(i);
  printf("%lld\n", rsp);
  return 0;
} 