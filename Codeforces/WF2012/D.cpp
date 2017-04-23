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

const int N = 200020;

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

string fib[101], fib2[101];
vector< Hash > completeS;

inline void preProcess() {
  fib[0] = fib2[0] = "0";
  fib[1] = fib2[1] = "1";
  for(int i = 2; i <= 100; ++i) {
    if(fib[i - 2].size() + fib[i - 1].size() <= 1e5) fib[i] = fib[i - 1] + fib[i - 2];
    else fib[i] = fib[i - 1];
    if(fib2[i - 2].size() + fib2[i - 1].size() <= 1e5) fib2[i] = fib2[i - 1] + fib2[i - 2];
    else fib2[i] = fib2[i - 2];
  } 
}

int n;
char s[N];
int len;
ll pd[N];

ll calc(int x) {
  int st = max((int)fib2[x - 1].size() - len + 1, 0);
  int ed = min((int)fib[x - 2].size(), len - 1);
  string sol = "";
  for(int i = st; i < fib2[x - 1].size(); ++i) sol.pb(fib2[x - 1][i]);
  for(int i = 0; i < ed; ++i) sol.pb(fib[x - 2][i]);
  vector< Hash > foo = build_hash(sol.size(), sol);
  ll sum = 0;
  for(int i = 0; i <= (int)sol.size() - len; ++i) {
    int ed = i + len - 1;
    if(get_hash(i, ed, foo) == completeS[len - 1]) {
      sum++;
    }
  }
  return sum;
}

inline void main2(int _test) {
  scanf(" %s", s);
  len = strlen(s);
  completeS = build_hash(len, (string)s);
  pd[0] = (len == 1 && s[0] == '0');
  pd[1] = (len == 1 && s[0] == '1');
  for(int x = 2; x <= n; ++x) pd[x] = pd[x - 1] + pd[x - 2] + calc(x);
  printf("Case %d: %lld\n", _test, pd[n]);
}


int main() {
  preProcess();
  int test = 1;
  while(scanf("%d", &n) != EOF) main2(test++);
  return 0;
}