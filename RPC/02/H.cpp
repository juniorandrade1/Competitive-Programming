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

const int N = 6 * 100000;

ll n, k;
vii v;
map< ll, int > idx;
set<ll>all;
int counter = 0;

bool cmp(ii a, ii b) {
  if(a.S != b.S) return a.S < b.S;
  else return a.F < b.F;
}

ll bit[N];

void update(int x, ll val) {
  x += 2;
  while(x < N) {
    bit[x] = max(bit[x], val);
    x += LSONE(x);
  }
}

ll query(int x) {
  x += 2;
  ll ret = 0;
  while(x) {
    ret = max(ret, bit[x]);
    x -= LSONE(x);
  }
  return ret;
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
  for(set<ll>::iterator it = all.begin(); it != all.end(); it++) idx[*it] = counter++;
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < k; ++i) {
    ll l = v[i].F, r = v[i].S;
    int idxR = idx[r];
    int idxL = idx[l - 1];
    ll at1 = (r - l + 1) + query(idxL);
    ll at2 = query(idxR); 
    update(idxR, max(at1, at2));
  }
  printf("%lld\n", n - query(N - 3));
  return 0;
}