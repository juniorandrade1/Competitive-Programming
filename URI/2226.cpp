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

const int N = 1e4 + 10;

const int MOD = 1e9 + 7, sigma = 26;
 
int term[N], len[N], to[N][sigma], link[N], sz = 1;

void add_str(string s) {
  int cur = 0;
  for(auto c: s) {
    if(!to[cur][c - '0']) {
      to[cur][c - '0'] = sz++;
      len[to[cur][c - '0']] = len[cur] + 1;
    }
    cur = to[cur][c - '0'];
  }
  term[cur] = cur; 
}

void push_links() {
  int que[sz];
  int st = 0, fi = 1;
  que[0] = 0;
  while(st < fi) {
    int V = que[st++];
    int U = link[V];
    if(!term[V]) term[V] = term[U];
    for(int c = 0; c < sigma; c++) {
      if(to[V][c]) {
        link[to[V][c]] = V ? to[U][c] : 0;
        que[fi++] = to[V][c];
      }
      else to[V][c] = to[U][c];
    }
  }
}

char s[123];
int llen = 0;
ll pd[20][N][2][2];

ll func(int pos, int node, int ok, int deuRuim) {
  if(pos == -1) return deuRuim;
  if(pd[pos][node][ok][deuRuim] != -1) return pd[pos][node][ok][deuRuim];
  ll ret = 0;
  if(ok) {
    for(int i = 0; i < 10; ++i) ret += func(pos - 1, to[node][i], ok, deuRuim | (term[node][i] != 0));
  }
  else {
    for(int i = 0; i < s[pos] - '0'; ++i) ret += func(pos - 1, to[node][i], 1, , deuRuim | (term[node][i] != 0));
    if(!term[to[node][s[pos] - '0']]) ret += func(pos - 1, to[node][s[pos] - '0'], 0, deuRuim | (term[node][i] != 0));
  }
  return pd[pos][node][ok][deuRuim] = ret;
}

ll solve(ll x) {
  push_links();
  llen = 0;
  while(x) {
    s[llen++] = (x % 10) + '0';
    x /= 10;
  }
  memset(pd, -1, sizeof pd);
  return func(llen - 1, 0, 0);
}

int main() {
  ll n;
  while(1) {
    scanf("%lld", &n);
    if(n == 0) break;
    int m; scanf("%d", &m);
    while(m--) {
      ll x; scanf("%lld", &x);
      string foo = "";
      while(x) {
        foo.pb((x % 10) + '0');
        x /= 10;
      }
      reverse(foo.begin(), foo.end());
      add_str(foo);
    }

    printf("%lld\n", solve(n));
  } 
  return 0;
}