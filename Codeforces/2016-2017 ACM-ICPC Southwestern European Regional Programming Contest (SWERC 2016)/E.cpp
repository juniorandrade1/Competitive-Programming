#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int MAXN = 100000, sigma = 36;
const ll md = 1000003;

inline ll addMod(ll a, ll b, ll MOD = md) {
  return ((a % md) + (b % md)) % md;
}
 

int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;

int getValue(char c) {
  if(c >= 'a' && c <= 'z') return c - 'a';
  if(c >= 'A' && c <= 'Z') return c - 'A';
  if(c == '0') return getValue('o');
  if(c == '1') return getValue('i');
  if(c == '3') return getValue('e');
  if(c == '5') return getValue('s');
  if(c == '7') return getValue('t');
  return c - '0' + 26;
}

void add_str(string s) {
  int cur = 0;
  for(auto c: s) {
    if(!to[cur][getValue(c)]) {
      to[cur][getValue(c)] = sz++;
      len[to[cur][getValue(c)]] = len[cur] + 1;
    }
    cur = to[cur][getValue(c)];
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

char str[MAXN];
int a, b, n;
ll pd[MAXN][32][2][2][2];

ll func(int no, int len, int hasUpper, int hasDown, int hasDigit) {
  if(len == 0) return (hasUpper & hasDown & hasDigit);
  if(pd[no][len][hasUpper][hasDown][hasDigit] != -1) return pd[no][len][hasUpper][hasDown][hasDigit];
  ll ret = 0;
  for(char i = 'a'; i <= 'z'; ++i) {
    int c = getValue(i);
    if(term[to[no][c]]) continue;
    ret = addMod(ret, func(to[no][c], len - 1, hasUpper, 1, hasDigit));
  }
  for(char i = 'A'; i <= 'Z'; ++i) {
    int c = getValue(i);
    if(term[to[no][c]]) continue;
    ret = addMod(ret, func(to[no][c], len - 1, 1, hasDown, hasDigit));
  }
  for(char i = '0'; i <= '9'; ++i) {
    int c = getValue(i);
    if(term[to[no][c]]) continue;
    ret = addMod(ret, func(to[no][c], len - 1, hasUpper, hasDown, 1));
  }
  return pd[no][len][hasUpper][hasDown][hasDigit] = ret;
}

int main() {
  scanf("%d %d %d", &a, &b, &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", str);
    add_str((string)str);
  } 
  push_links();
  memset(pd, -1, sizeof pd);
  ll ans = 0;
  for(int i = a; i <= b; ++i) ans = addMod(ans, func(0, i, 0, 0, 0));
  printf("%lld\n", ans);
  return 0;
}