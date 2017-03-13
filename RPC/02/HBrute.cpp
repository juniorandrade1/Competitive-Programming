#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 1000000000000000000LL
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

const int N = 5 * (1e5 + 10);

ll n, k;
vii v;
map< ll, int > idx;
map< int, ll > rev;
set<ll>all;
ll pd[N];

bool cmp(ii a, ii b) {
  if(a.S != b.S) return a.S < b.S;
  else return a.F < b.F;
}


int main() {
  scanf("%lld %lld", &n, &k);
  all.insert(0); all.insert(n);
  for(int i = 0; i < k; ++i) {
    ll l, r; scanf("%lld %lld", &l, &r);
    all.insert(l - 1);
    all.insert(r);
    v.pb(mp(l, r));
  }
  int counter = 0;
  for(set<ll>::iterator it = all.begin(); it != all.end(); it++) idx[*it] = counter, rev[counter++] = *it;
  sort(v.begin(), v.end(), cmp);
  //build(1, 0, counter - 1);
  
  ll ans = n;
  
  for(int i = 0; i < k; ++i) {
    ll l = v[i].F, r = v[i].S;
    int idxR = idx[r];
    pd[idxR] = l - 1;
    for(int j = 0; j < i; ++j) {
      if(v[j].S < v[i].F) {
        pd[idxR] = min(pd[idxR], (v[i].F - v[j].S - 1) + pd[idx[v[j].S]]);
      }
    } 
    ans = min(ans, pd[idxR] + (n - r));
  }
  printf("%lld\n", ans);

  return 0;
}