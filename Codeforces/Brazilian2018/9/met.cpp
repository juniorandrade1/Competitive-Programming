  #include <bits/stdc++.h>

  using namespace std;

  typedef long long ll;

  typedef unsigned long long ull;
  typedef pair<ll,ll> ii;
  typedef vector<ll> vi;
  typedef vector< ii > vii;

  #define INF 0x3F3F3F3F
  #define LINF 0x3F3F3F3F3F3F3F3FLL
  #define pb push_back
  #define mp make_pair
  #define pq priority_queue
  #define LSONE(s) ((s)&(-s)) //LASTBIT
  #define DEG_to_RAD(X)   (X * PI / 180)
  #define F first
  #define S second

   
  #ifdef ONLINE_JUDGE
  #define debug(args...)
  #else
  #define debug(args...) fprintf(stderr,args)
  #endif

  //////////////////////
  int dx[] = {1,-1,0,0};
  int dy[] = {0,0,-1,1};  
  //////////////////////

  const int N = 600020;
  const int SQ = 500;

  struct Query {
    int l, r;
    ll x;
    Query(){};
    Query(int _l, int _r, ll _x) {
      l = _l;
      r = _r;
      x = _x;
    } 
    void read() {
      scanf("%d %d %lld", &l, &r, &x);
    }
  };

  int n, m, q;
  ll o[N], p[N];
  Query que[N];
  int sol[N];
  vector< int > g[N];

  ll csum[2][N];

  void update(int op, int x, ll v) {
    x += 2;
    while(x < N) {
      csum[op][x] += v;
      x += LSONE(x);
    }
  }

  ll query(int op, int x) {
    x += 2;
    ll ret = 0;
    while(x) {
      ret += csum[op][x];
      x -= LSONE(x);
    }
    return ret;
  }

  inline ll getValues(int op, int i) {
    ll foo = 0;
    for(int j = 0; j < g[i].size(); ++j) {
      foo += query(op, g[i][j]);
      foo += query(op, g[i][j] + m);
    }
    return foo;
  }

  inline void trySolve(set< int > &np, int op, int l, int r) {
    memcpy(csum[op], csum[op ^ 1], sizeof csum[op ^ 1]);
    r = min(r, q - 1);
    for(int i = l; i <= r; ++i) {
      update(op, que[i].l, que[i].x);
      update(op, que[i].r + 1, -que[i].x);
      vector< int > remov;
      for(set < int > :: iterator it = np.begin(); it != np.end(); it++) {
        int x = *it;
        if(getValues(op, x) >= p[x]) {
          sol[x] = i + 1;
          remov.pb(*it);
        }
      }
      for(int j = 0; j < remov.size(); ++j) np.erase(np.find(remov[j]));
    }
  }

  void go() {
    memset(csum[0], 0, sizeof csum[0]);
    for(int i = 0; i < q; ++i) {
      update(0, que[i].l, que[i].x);
      update(0, que[i].r + 1, -que[i].x);
    }
    for(int i = 0; i < n; ++i) {
      ll foo = getValues(0, i);
      if(foo < p[i]) sol[i] = -INF;
    }
    int op = 0;
    memset(csum[0], 0, sizeof csum[0]);
    for(int i = 0; i < q; i += SQ) {
      op ^= 1;
      memcpy(csum[op], csum[op ^ 1], sizeof csum[op ^ 1]);
      for(int j = 0; j < SQ && j + i < q; ++j) {
        update(op, que[i + j].l, que[i + j].x);
        update(op, que[i + j].r + 1, -que[i + j].x);
      }
      set< int > np;
      for(int j = 0; j < n; ++j) {
        int x = j;
        if(getValues(op, x) >= p[x] && getValues(op ^ 1, x) < p[x]) np.insert(x);
      }
      trySolve(np, op, i, i + SQ - 1);
    }
  }

  int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
      scanf("%lld", o + i); o[i]--;
      g[o[i]].pb(i);
    }
    for(int i = 0; i < n; ++i) scanf("%lld", p + i);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
      int l, r; ll x; scanf("%d %d %lld", &l, &r, &x);
      l--; r--;
      if(l > r) r += m;
      que[i] = Query(l, r, x);
    }
    go();
    for(int i = 0; i < n; ++i) {
      if(sol[i] == -INF) puts("NIE");
      else printf("%d\n", sol[i]);
    }
    return 0;
  } 