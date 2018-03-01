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

const int N = 2000010;

int n;
int v[N];
map< int, int > all;

int main() {
  scanf("%d", &n);
  ll ans = 0;
  ll allNeg = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%d", v + i);
    ll tot = i;
    ll qm = all[v[i] - 1];
    ll qa = all[v[i]];
    ll qp = all[v[i] + 1];
    ll qc = tot - qm - qa - qp;
    ll tm = qm * (ll)(v[i] - 1LL);
    ll ta = qa * (ll)v[i];
    ll tp = qp * (ll)(v[i] + 1LL);
    ans += (ll)v[i] * qc;
    ans -= (allNeg - tm - ta - tp);
    allNeg += v[i];
    all[v[i]]++;
  }
  printf("%lld\n", ans);
  return 0;
}
