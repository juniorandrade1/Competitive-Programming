#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 1000000000000000010LL
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

typedef long double CHType;

#define CHINF HUGE_VAL

struct Line {
  CHType m, b;
  Line(){};
  Line(CHType _m, CHType _b) {
    m = _m;
    b = _b;
  }
  bool operator < (Line other) const {
    if(m != other.m) return m > other.m;
    return b > other.b;
  }
  CHType getVal(CHType x) {
    return m * x + b;
  }
};

struct ConvexHullTrick {
  vector< Line > st;
  bool badLine(Line s, Line t, Line u) {
    if(t.m == u.m) return true;
    return 1.0 * (t.b - s.b) * (s.m - u.m) >= 1.0 * (u.b - s.b) * (s.m - t.m); //don't forget 1.0
  }
  void addLine(Line l) {
    while(st.size() >= 2 && badLine(st[st.size() - 2], st[st.size() - 1], l)) st.pop_back();
    st.push_back(l);
  }
  CHType query(CHType x) {
    if(st.size() == 0) return CHINF;
    int lo = 0, hi = st.size() - 1;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(st[md].getVal(x) <= st[md + 1].getVal(x)) hi = md;
      else lo = md + 1;
    }
    return st[lo].getVal(x);
  }
};

const int N = 210;
const int M = 15;

int n, q;
ll dp[N + 1];
vector< Line > ln[M + 1];
ConvexHullTrick ch[M + 1];

inline ll solve(ll a, ll b) {
  for(int i = 0; i <= N; ++i) dp[i] = LINF;
  dp[0] = 0;
  for(int i = 1; i <= M; ++i) for(int j = 0; j <= N; ++j) {
    CHType sol = ch[i].query(b);
    if(sol == HUGE_VAL) continue;
    dp[j] = min(dp[j], (ll)(dp[max(j - i, 0)] + sol));
  }
  ll ans = LINF;
  for(int i = 1; i <= N; ++i) {
    if(dp[i] >= LINF) continue;
    ll q = a / i;
    ans = min(ans, q * dp[i] + dp[a % i]);
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) {
    int c, s, p; scanf("%d %d %d", &c, &s, &p);
    ln[c].pb(Line(p, s - p));
  }
  for(int i = 1; i <= M; ++i) {
    sort(ln[i].begin(), ln[i].end());
    for(int j = 0; j < ln[i].size(); ++j) ch[i].addLine(ln[i][j]);
  }
  for(int i = 0; i < q; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    printf("%lld\n", solve(a, b));
  }
  return 0;
}