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

const int MAXN = N, MOD = 1e9 + 7, sigma = 10;
 
int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;

void add_str(string s) {
  int cur = 0;
  for(int i = 0; i < s.size(); ++i) {
    int op = s[i] - 'a';
    if(!to[cur][op]) {
      to[cur][op] = sz++;
      len[to[cur][op]] = len[cur] + 1;
    }
    cur = to[cur][op];
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

int n, m, l;
char s[N];
int pd[N][51];
short memo[N][51];

int func(int node, int f) {
  if(f == 0 || term[node]) return 0;
  if(memo[node][f]) return pd[node][f];
  memo[node][f] = 1;
  ll a = 0;
  for(int i = 0; i < l; ++i) a |= (1LL << func(to[node][i], f - 1));
  int qtd = 0;
  while(a & 1) {
    qtd++;
    a >>= 1;
  }
  return pd[node][f] = qtd;
}

int main() {
  scanf("%d %d", &n, &l);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    add_str((string)s);
  }
  push_links();
  int nim = 0;
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int f; scanf(" %s %d", s, &f);
    n = strlen(s);
    int x = 0;
    for(int j = 0; j < n; ++j) x = to[x][s[j] - 'a'];
    nim ^= func(x, f);
  } 
  puts(nim ? "Tyrion" : "Daenerys");
  return 0;
}