#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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
#define pi acos(-1.0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

inline void file() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

#define MAXN 50050

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

Hash pot[MAXN];

vector<Hash> build_hash(int n, HType *v) {
  pot[0] = Hash(1, 1);
  vector<Hash> ret;
  Hash acc;
  for(int i = 0; i < n; i++) {
    acc.append(v[i]);
    ret.push_back(acc);
    if(i > 0) pot[i] = pot[i - 1] * Hash(P1, P2);
  }
  return ret;
}

inline Hash get_hash(int l, int r, vector<Hash> &hashv) {
  if(l == 0) return hashv[r];
  return hashv[r] - hashv[l - 1] * pot[r - l + 1];
}

const int N = 111;
const int M = 55555;

vector<Hash> wordsHash[N];
int len[N];
int n;
char str[M];
int pd[N][M];

int func(int pos, int idx) {
  if(pd[pos][idx] != -1) return pd[pos][idx];
  pd[pos][idx] = 0;
  for(int i = 0; i < n; ++i) {
    if(pos == 0 && i == idx) continue;
    if(len[i] + pos == len[idx]) {
      Hash a = get_hash(pos, pos + len[i] - 1, wordsHash[idx]);
      Hash b = get_hash(0, len[i] - 1, wordsHash[i]);
      if(a == b) return pd[pos][idx] = 1;
    }
    else if(len[i] + pos < len[idx]) {
      Hash a = get_hash(pos, pos + len[i] - 1, wordsHash[idx]);
      Hash b = get_hash(0, len[i] - 1, wordsHash[i]);
      if(a == b) pd[pos][idx] |= func(pos + len[i], idx);
    }
    else {
      int qtd = len[idx] - pos;
      Hash a = get_hash(pos, pos + qtd - 1, wordsHash[idx]);
      Hash b = get_hash(0, qtd - 1, wordsHash[i]);
      if(a == b) pd[pos][idx] |= func(qtd, i);
    }
  }
  return pd[pos][idx];
}

int main() {
  //file();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", str);
    len[i] = strlen(str);
    wordsHash[i] = build_hash(len[i], str);
  }
  memset(pd, -1, sizeof pd);
  int ans = 0;
  for(int i = 0; i < n && !ans; ++i) ans |= func(0, i);
  printf("%s\n", ans ? "YES" : "NO");
  return 0;
}