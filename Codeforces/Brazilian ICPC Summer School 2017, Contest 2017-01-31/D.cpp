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

const int N = 1e5 + 10;
#define MAXN (ll)1e5 + 10

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
  Hash operator + (Hash that) const{
    return Hash( (h1 + that.h1)%MOD, (h2 + that.h2)%MOD);
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

char s[N];
vector< Hash > ok, rev, need;
int n;

int main() {
  scanf(" %s", s);
  n = strlen(s);
  ok = build_hash(n, s);
  reverse(s, s + strlen(s));
  rev = build_hash(n, s);
  scanf(" %s", s);
  need = build_hash(n, s);
  Hash all = get_hash(0, n - 1, need);

  if(get_hash(0, n - 1, ok) == all) {
    puts("Yes");
    puts("0");
    exit(0);
  }


  for(int i = 0; i + 1 < n; ++i) {
    int c1 = i;
    int c2 = i + 1;
    Hash start = get_hash(c2, n - 1, ok);
    Hash fim = get_hash(n - c1 - 1, n - 1, rev);
    Hash re = start * pot[i + 1] + fim;
    if(re == all) {
      puts("Yes");
      printf("%d\n", i + 1);
      exit(0);
    }
  }

  if(get_hash(0, n - 1, rev) == all) {
    puts("Yes");
    printf("%d\n", n);
    exit(0);
  }

  puts("No");

  return 0;
}