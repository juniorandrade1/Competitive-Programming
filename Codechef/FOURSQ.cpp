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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif


const int N = 1000010;

ll tr[4 * N];
ll n, q, p; 

ll mulMod(ll a, ll b, ll c = p){
  ll x = 0, y = a % c;
    while(b > 0) {
      if(b % 2 == 1) x = (x + y) % c;
      y = (y * 2LL) % c;
      b /= 2LL;
    }
  return x%c;
}


void update(int no, int l, int r, int i, ll val) {
  if(l == r) {
    tr[no] = val;
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, val);
  else update(nxt + 1, mid + 1, r, i, val);
  tr[no] = mulMod(tr[nxt], tr[nxt + 1]);
}

ll query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 1;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return mulMod(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

ll pre[1000002];

inline void __query(int l, int r) {
  ll s = query(1, 0, n - 1, l, r);
  ll id1 = lower_bound(pre, pre + 1000001, s + 1) - pre - 1;
  s -= pre[id1];
  ll id2 = lower_bound(pre, pre + 1000001, s + 1) - pre - 1;
  s -= pre[id2];
  ll id3 = lower_bound(pre, pre + 1000001, s + 1) - pre - 1;
  s -= pre[id3];
  ll id4 = lower_bound(pre, pre + 1000001, s + 1) - pre - 1;
  s -= pre[id4];
  if(s) puts("-1");
  else printf("%lld %lld %lld %lld\n", id1, id2, id3, id4);
}

inline void main2() {
  scanf("%lld %lld %lld", &n, &q, &p);
  for(int i = 0; i < n; ++i) {
    ll v; scanf("%lld", &v);
    update(1, 0, n - 1, i, v);
  }
  while(q--) {
    ll t, l, r; scanf("%lld %lld %lld", &t, &l, &r);
    if(t == 1) update(1, 0, n - 1, l - 1, r);
    else __query(l - 1, r - 1);
  }
}

int main() {
  for(int i = 0; i <= 1000000; ++i) pre[i] = (ll)i * i;
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}