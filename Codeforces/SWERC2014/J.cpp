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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define MAXN 2020

const int N = 2020;

typedef char HType;

const int P1 = 31, P2 = 37, MOD = (int)1e9 + 7;
struct Hash {
  ll h1, h2;
  Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
  void append(HType c) {
    h1 = (P1*h1 + c) % MOD;
    h2 = (P2*h2 + c) % MOD;
  }
  bool operator== (Hash that) const {
    return h1 == that.h1 && h2 == that.h2;
  }
  bool operator!= (Hash that) const {
    return h1 != that.h1 || h2 != that.h2;
  }
  Hash operator* (Hash that) const {
    return Hash((h1*that.h1)%MOD, (h2*that.h2)%MOD);
  }
  Hash operator- (Hash that) const {
    return Hash( (h1 - that.h1 + MOD)%MOD, (h2 - that.h2 + MOD)%MOD);
  }
  bool operator < (Hash foo) const {
    if(h1 != foo.h1) return h1 < foo.h1;
    return h2 < foo.h2;
  }
};

Hash pot[MAXN];

vector<Hash> build_hash(int n, HType *v) {
  pot[0] = Hash(1,1);
  vector<Hash> ret;
  Hash acc;
  for(int i = 0; i < n; i++) {
  acc.append(v[i]);
  ret.push_back(acc);
  if(i > 0) pot[i] = pot[i-1] * Hash(P1, P2);
  }
  return ret;
}

inline Hash get_hash(int l, int r, vector<Hash> &hashv) {
  if(l == 0) return hashv[r];
  return hashv[r] - hashv[l-1] * pot[r-l+1];
}


vector<int> Z(vector<int> s) {
  vector<int> z(1,s.size());
  int l=0,r=0;
  for(int a=1;a<(int)s.size();++a) {
  if(r < a) {
    l = r = a;
  while(r<(int)s.size() && s[r] == s[r-l]) ++r;
  z.push_back(r-l);
  r--;
  }
  else if(z[a-l] < r-a+1) z.push_back(min<int>(z[a-l],s.size()-a));
  else {
  l = a;
  while(r<(int)s.size() && s[r] == s[r-l]) ++r;
  z.push_back(r-l);
  r--;
  }
  }
  return z;
}


int n1, m1, n2, m2;
char s[N][N], p[N][N];

int atIndex = 0;
map< Hash, int > idx;

vector< int > vectorPattern;
vector< int > g[N];

int main() {
  scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
  for(int i = 0; i < n1; ++i) {
    scanf(" %s", s[i]);
    vector< Hash > lineHash = build_hash(m1, s[i]);
    Hash totHash = get_hash(0, m1 - 1, lineHash);
    if(idx.find(totHash) == idx.end()) idx[totHash] = atIndex++;
    vectorPattern.pb(idx[totHash]);
  }
  for(int i = 0; i < n2; ++i) scanf(" %s", p[i]);

  for(int i = 0; i < n2; ++i) {
    vector< Hash > lineHash = build_hash(m2, p[i]);
    for(int j = 0; j + m1 <= m2; ++j) {
      Hash totHash = get_hash(j, j + m1 - 1, lineHash);
      if(idx.find(totHash) == idx.end()) g[j].pb(-1);
      else g[j].pb(idx[totHash]);
    }
  }

  int ans = 0;
  for(int i = 0; i + m1 <= m2; ++i) {
    vector<int> at = vectorPattern;
    at.pb(INF);
    for(int j = 0; j < g[i].size(); ++j) at.pb(g[i][j]);
    vector<int>algo = Z(at);
    for(int j = vectorPattern.size(); j < algo.size(); ++j) ans += algo[j] == vectorPattern.size();
  }
  printf("%d\n", ans);
  return 0;
}