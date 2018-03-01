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

const int N = 2500001;
const int B = 400;

int n, q;
int v[N];
vector< int > id[N];
set< int > s;
int nv[N];

inline void process() {
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    v[*it] = nv[*it];
    nv[*it] = 0;
  }
  s.clear();
  for(int i = 0; i < N; ++i) {
    id[i].clear();
  }
  id[0].pb(0);
  int x = 0;
  for(int i = 1; i <= n; ++i) {
    x ^= v[i];
    id[x].pb(i);
  }
}

inline void update(int i, int x) {
  s.insert(i);
  nv[i] = x;
  if(s.size() >= B) process();
}

inline int query(int i, int k) {
  int sol = 0;
  int lst = 0;
  int at = k;
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    int f = min(*it, i + 1);
    sol += (lower_bound(id[at].begin(), id[at].end(), f) - lower_bound(id[at].begin(), id[at].end(), lst));
    at ^= (nv[*it] ^ v[*it]);
    lst = f;
  }
  if(lst <= i) sol += (lower_bound(id[at].begin(), id[at].end(), i + 1) - lower_bound(id[at].begin(), id[at].end(), lst));
  return sol;
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  process();
  while(q--) {
    int op, l, r; scanf("%d %d %d", &op, &l, &r);
    if(op == 1) update(l, r);
    else printf("%d\n", query(l, r));
  }
  return 0;
}