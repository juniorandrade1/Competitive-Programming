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

#define pi acos(-1.0)

const int N = 300010;
int B = 400;
const int Q = 350;

struct Query {
  int l, r, k, id;
  Query(){};
  Query(int _l, int _r, int _k, int _id) {
    l = _l;
    r = _r;
    k = _k;
    id = _id;
  }
  bool operator < (Query other) {
    if(l / B != other.l / B) return l / B < other.l / B;
    return r > other.r;
  }
};

int n, q;
vi g[N];
int v[N];
int cnt[N];
Query all[N];
int sol[N];

int main() {
  srand(94739534513L + time(NULL));
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  for(int i = 0; i < q; ++i) {
    int l, r, k; scanf("%d %d %d", &l, &r, &k);
    all[i] = Query(l, r, k, i);
  } 
  B = sqrt(n);
  sort(all, all + q);
  int lm = 0, rm = 0;
  for(int i = 0; i < q; ++i) {
    while(rm < all[i].r) cnt[v[++rm]]++;
    while(rm > all[i].r) cnt[v[rm--]]--;
    while(lm < all[i].l) cnt[v[lm++]]--;
    while(lm > all[i].l) cnt[v[--lm]]++;
    int bst = INF;
    int ln = all[i].r - all[i].l + 1;
    int nd = ln / all[i].k;
    for(int j = 0; j < Q; ++j) {
      int idx = all[i].l + (rand() % ln);
      int x = v[idx];
      if(x > bst || cnt[x] <= nd) continue;
      bst = x;
    }
    if(bst == INF) bst = -1;
    sol[all[i].id] = bst;
  }
  for(int i = 0; i < q; ++i) {
    printf("%d\n", sol[i]);
  }
  return 0;
}