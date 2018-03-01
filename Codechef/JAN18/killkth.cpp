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

const ll N = 400000;
const ll NS = 400000;
 
ll cn, cd, ns, en = 1, lst;
string S[NS]; ll si = -1;
vector<ll> sufn[N];
 
struct node {
  ll l, r, si;
  ll p, suf, ct;
  map<char, ll> adj;
  node() : l(0), r(-1), suf(0), p(0) {}
  node(ll L, ll R, ll S, ll P) : l(L), r(R), si(S), p(P), ct(0) {}
  inline ll len() { return r - l + 1; }
  inline ll operator[](ll i) { return S[si][l + i]; }
  inline ll& operator()(char c) { return adj[c]; }
} t[N];
 
inline ll new_node(ll L, ll R, ll S, ll P) {
  t[en] = node(L, R, S, P);
  return en++;
}
 
void add_string(string s) {
  s += '$';
  S[++si] = s;
  sufn[si].resize(s.size() + 1);
  cn = cd = 0;
  ll i = 0; const ll n = s.size();
  for(ll j = 0; j < n; j++) {
    for(; i <= j; i++) {
      if(cd == t[cn].len() && t[cn](s[j]))
        cn = t[cn](s[j]), cd = 0;
      if(cd < t[cn].len() && t[cn][cd] == s[j]) {
        cd++;
        if(j < s.size() - 1) break;
        else {
          if(i) t[lst].suf = cn;
          for(; i <= j; i++) {
            sufn[si][i] = cn;
            cn = t[cn].suf;
          }
        }
      } else if(cd == t[cn].len()) {
        sufn[si][i] = en;
        if(i) t[lst].suf = en; lst = en;
        t[cn](s[j]) = new_node(j, n - 1, si, cn);
        cn = t[cn].suf;
        cd = t[cn].len();
      } else {
        ll mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
        t[t[cn].p](t[cn][0]) = mid;
        if(ns) t[ns].suf = mid;
        if(i) t[lst].suf = en; lst = en;
        sufn[si][i] = en;
        t[mid](s[j]) = new_node(j, n - 1, si, mid);
        t[mid](t[cn][cd]) = cn;
        t[cn].p = mid; t[cn].l += cd;
        cn = t[mid].p;
        ll g = cn? j - cd : i + 1;
        cn = t[cn].suf;
        while(g < j && g + t[t[cn](S[si][g])].len() <= j)
          cn = t[cn](S[si][g]), g += t[cn].len();
        if(g == j)
          ns = 0, t[mid].suf = cn, cd = t[cn].len();
        else
          ns = mid, cn = t[cn](S[si][g]), cd = j - g;
      }
    }
  }
}

char str[N];
ll active[N], sub[N];
ll dp[N];

inline ll get(ll x) { return (x * (x + 1LL)) / 2LL; }

void dfs(ll x, ll len) {
  if(t[x].adj.empty()) len--;
  sub[x] = dp[x] = 0;
  for(map<char, ll>::iterator it = t[x].adj.begin(); it != t[x].adj.end(); it++) {
    ll y = it->S;
    dfs(y, len + t[y].len()); 
    active[x] += active[y];
    sub[x] += sub[y];
    dp[x] += dp[y];
  }
  ll la = t[x].len() - t[x].adj.empty();
  ll lb = (len - la);
  dp[x] += (get(la) + la * lb) * active[x];
  sub[x] += la * active[x];
}

char goKth(ll x, ll len, ll k) {
  if(t[x].adj.empty()) len--;
  ll la = t[x].len() - t[x].adj.empty();
  ll lb = (len - la);
  ll qtdAr = (get(la) + la * lb) * active[x];
  if(qtdAr >= k) {
    ll lo = 0, hi = la;
    while(lo < hi) {
      ll md = (lo + hi + 1) >> 1;
      ll q = (get(md) + md * lb) * active[x];
      if(q < k) lo = md;
      else hi = md - 1;
    }
    k -= (get(lo) + lo * lb) * active[x];
    lo += lb + 1;
    k--;
    k %= lo;
    k++;
    return t[x][k - 1 - lb];
  }
  else {
    k -= qtdAr;
    for(map<char, ll>::iterator it = t[x].adj.begin(); it != t[x].adj.end(); it++) {
      ll y = it->S;
      if(dp[y] < k) k -= dp[y];
      else return goKth(y, len + t[y].len(), k);
    }
  }
}
 

inline char getKth(ll k) {
  return goKth(0, 0, k);
}

int main() {
  scanf(" %s", str);
  add_string((string)str);
  for(int i = 0; i < S[0].size(); ++i) active[sufn[0][i]]++;  
  dfs(0, 0);
  ll q; scanf("%lld", &q);  
  ll g = 0;
  while(q--) {
    ll p, k, m; scanf("%lld %lld", &p, &m);
    k = (p * g) % m + 1;
    char c = getKth(k);
    g += (ll)c;
    printf("%c\n", c);
  }
  return 0;
}