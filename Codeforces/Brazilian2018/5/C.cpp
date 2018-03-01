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

const int N = 1000010;

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
  bool operator < (Hash that) const {
    if(h1 != that.h1) return h1 < that.h1;
    return h2 < that.h2;
  }
  
};

Hash pot[N];

vector<Hash> build_hash(int n, char *v) {
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

inline Hash get_hash(vector<Hash> &hashv, int l, int r) {
  if(l == 0) return hashv[r];
  return hashv[r] - hashv[l-1] * pot[r-l+1];
}

char s[N], t[N];
int ls, lt;
vector< Hash > hs, ht, rs, rt;

int main() {
  scanf(" %s %s", s, t);
  ls = strlen(s);
  lt = strlen(t);
  hs = build_hash(ls, s);
  ht = build_hash(lt, t);
  reverse(s, s + ls);
  reverse(t, t + lt);
  rs = build_hash(ls, s);
  rt = build_hash(lt, t);
  int k; scanf("%d", &k);
  vector< int > solution;
  for(int l = 0; l + lt - 1 < ls; ++l) {
    int r = l + lt - 1;
    if(get_hash(hs, l, r) == get_hash(ht, 0, lt - 1)) solution.pb(l + 1);
    else {
      int lo, hi;

      lo = 0; hi = lt;
      while(lo < hi) {
        int md = (lo + hi) >> 1;
        if(get_hash(hs, l, l + md) == get_hash(ht, 0, md)) lo = md + 1;
        else hi = md;
      }

      int ml = lo;

      int revR = ls - r - 1;
      lo = 0; hi = lt;
      while(lo < hi) {
        int md = (lo + hi) >> 1;
        if(get_hash(rs, revR, revR + md) == get_hash(rt, 0, md)) lo = md + 1;
        else hi = md;
      }

      int mr = lo;


      if(r - l + 1 - (ml + mr) <= k) solution.pb(l + 1);
    }
  }

  printf("%d\n", (int)solution.size());
  for(int i = 0; i < (int)solution.size(); ++i) {
    if(i) printf(" ");
    printf("%d", solution[i]);
  }
  printf("\n");
  return 0;
}



