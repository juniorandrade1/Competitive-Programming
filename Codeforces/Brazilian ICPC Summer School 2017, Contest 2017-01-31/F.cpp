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

const ll md = 1000000009;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

const int N = 200020;

typedef char HType;

const int P1 = 31, P2 = 37, MOD = (int)1e9 + 7, MOD2 = md;

struct Hash {
  ll h1, h2;
  Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
  void append(HType c) {
    h1 = (P1*h1 + c) % MOD;
    h2 = (P2*h2 + c) % MOD2;
  }
  bool operator== (Hash that) const {
    return h1 == that.h1 && h2 == that.h2;
  }
  bool operator!= (Hash that) const {
    return h1 != that.h1 || h2 != that.h2;
  }
  Hash operator* (Hash that) const {
    return Hash((h1*that.h1)%MOD, (h2*that.h2)%MOD2);
  }
  Hash operator- (Hash that) const {
    return Hash( (h1 - that.h1 + MOD)%MOD, (h2 - that.h2 + MOD2)%MOD2);
  }
};

Hash pot[N];

vector<Hash> build_hash(int n, string v) {
  pot[0] = Hash(1, 1);
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

string fib[20001], fib2[20001];
vector< Hash > completeS;

int n;
char s[N];
int len;
ll pd[N];

ll calc(int x) {
  int st = max((int)fib2[x - 2].size() - len + 1, 0);
  int ed = min((int)fib[x - 1].size(), len - 1);
  string sol = "";
  for(int i = st; i < fib2[x - 2].size(); ++i) sol.pb(fib2[x - 2][i]);
  for(int i = 0; i < ed; ++i) sol.pb(fib[x - 1][i]);
  vector< Hash > foo = build_hash(sol.size(), sol);
  ll sum = 0;
  for(int i = 0; i <= (int)sol.size() - len; ++i) {
    int ed = i + len - 1;
    if(get_hash(i, ed, foo) == completeS[len - 1]) {
      sum++;
      if(sum >= md) sum -= md;
    }
  }
  return sum;
}

int main() {
  scanf(" %s", s);
  len = strlen(s);
  completeS = build_hash(len, (string)s);
  scanf("%d", &n);
  fib[0] = fib2[0] = "";
  fib[1] = fib2[1] = "a";
  fib[2] = fib2[2] = "b";
  for(int i = 3; i <= n; ++i) {
    if(fib[i - 2].size() + fib[i - 1].size() <= 1e4 * 2) fib[i] = fib[i - 2] + fib[i - 1];
    else fib[i] = fib[i - 1];
    if(fib2[i - 2].size() + fib2[i - 1].size() <= 1e4 * 2) fib2[i] = fib2[i - 2] + fib2[i - 1];
    else fib2[i] = fib2[i - 1];
  } 
  pd[0] = (len == 0);
  pd[1] = (len == 1 && s[0] == 'a');
  pd[2] = (len == 1 && s[0] == 'b');
  for(int x = 3; x <= n; ++x) pd[x] = addMod(pd[x - 1], addMod(pd[x - 2], calc(x)));
  printf("%lld\n", pd[n] % md);
  return 0;
}