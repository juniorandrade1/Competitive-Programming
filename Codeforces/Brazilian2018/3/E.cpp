
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

const int N = 101;
const int M = 1001;

struct Node {
  ll ep;
  ll et;
  Node(){
    ep = 0;
    et = 0;
  };
  Node(ll _ep, ll _et) {
    et = _et;
    ep = _ep;
  }
  bool operator > (Node o) const {
    if(ep != o.ep) return ep > o.ep;
    return et < o.et;
  }
  bool operator < (Node o) const {
    if(ep != o.ep) return ep < o.ep;
    return et > o.et;
  }
  bool operator == (Node o) const {
    return ep == o.ep && et == o.et;
  }
};

struct Problems {
  ll t, p, id;
  Problems(){};
  Problems(ll _t, ll _p, ll _id) {
    t = _t;
    p = _p;
    id = _id;
  }
  bool operator < (Problems o) const {
    return t * o.p < p * o.t;
  }
};

Node pd[N][M];
short memo[N][M];
Problems v[N];
int n, t;

Node func(int pos, int qt) {
  if(pos == n) return Node();
  if(memo[pos][qt]) return pd[pos][qt];
  memo[pos][qt] = 1;
  Node sol = func(pos + 1, qt);
  if(qt + v[pos].t <= t) {
    Node ax = func(pos + 1, qt + v[pos].t);
    ax.ep += v[pos].p;
    ax.et += v[pos].p * (qt + v[pos].t);
    sol = max(sol, ax);
  }
  return pd[pos][qt] = sol;
}

vector< int > solution;

void back(int pos, int qt) {
  if(pos == n) return;
  Node sol = func(pos + 1, qt);
  if(pd[pos][qt] == sol) {
    back(pos + 1, qt);
  }
  else {
    solution.pb(v[pos].id);
    back(pos + 1, qt + v[pos].t);
  }
}

int main() {
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; ++i) {
    ll a, b; scanf("%lld %lld", &a, &b);
    v[i] = Problems(a, b, i + 1);
  }
  sort(v, v + n);
  Node sol = func(0, 0);
  debug("%lld %lld\n", sol.ep, sol.et);
  back(0, 0);
  printf("%d\n", (int)solution.size());
  for(int i = 0; i < (int)solution.size(); ++i) {
    if(i) printf(" ");
    printf("%d", solution[i]);
  }
  printf("\n");
  return 0;
}