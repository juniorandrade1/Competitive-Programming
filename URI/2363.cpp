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
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

vi rec(vi v) {
  if(v.size() <= 1) return v;
  vi imp, par;
  for(int i = 0; i < v.size(); i += 2) imp.pb(v[i]);
  for(int i = 1; i < v.size(); i += 2) par.pb(v[i]);
  par = rec(par);
  imp = rec(imp);
  vi out;
  for(int i = 0; i < par.size(); ++i) out.pb(par[i]);
  for(int i = 0; i < imp.size(); ++i) out.pb(imp[i]);
  return out;
}

int main() {
  //arquivo();
  ll n, a, b;
  vi s;
  scanf("%lld", &n);
  //scanf("%lld %lld %lld", &n, &a, &b);
  for(int i = 1; i <= n; ++i) s.pb(i);
  s = rec(s);
  for(int i = 0; i < s.size(); ++i) debug("%lld ", s[i]);
    debug("\n");
  return 0;
}