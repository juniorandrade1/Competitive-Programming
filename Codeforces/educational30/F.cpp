#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair< ull, ull > ii;
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

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////


#define MAXN 220000
int n, t;
int p[MAXN],r[MAXN],h[MAXN];

string s;
void fix_index(int *b, int *e) {
  int pkm1, pk, np, i, d, m;
  pkm1 = p[*b + t];
  m = e - b; d = 0;
  np = b - r;
  for(i = 0; i < m; i++) {
    if (((pk = p[*b+t]) != pkm1) && !(np <= pkm1 && pk < np+m)) {
      pkm1 = pk;
      d = i;
    }
    p[*(b++)] = np + d;
  }
}
bool comp(int i, int j) {
  return p[i + t] < p[j + t];
}
void suff_arr() {
  int i, j, bc[256];
  t = 1;
  for(i = 0; i < 256; i++) bc[i] = 0;
  //alfabeto
  for(i = 0; i < n; i++) ++bc[int(s[i])]; //counting sort inicial del alfabeto
  for(i = 1; i < 256; i++) bc[i] += bc[i - 1];
  for(i = 0; i < n; i++) r[--bc[int(s[i])]] = i;
  for(i = n - 1; i >= 0; i--) p[i] = bc[int(s[i])];
  for(t = 1; t < n; t *= 2) {
  for(i = 0, j = 1; i < n; i = j++) {
    while(j < n && p[r[j]] == p[r[i]]) ++j;
      if (j - i > 1) {
        sort(r + i, r + j, comp);
        fix_index(r + i, r + j);
      }
    }
  }
}
void lcp() {
  int tam = 0, i, j;
  for(i = 0; i < n; i++) if (p[i] > 0) {
    j = r[p[i] - 1];
    while(s[i + tam] == s[j + tam]) ++tam;
    h[p[i] - 1] = tam;
    if (tam > 0) --tam;
  }
  h[n - 1] = 0;
}

const int N = 200005;

char str[N];
int esq[N], dir[N];
int a[N], forbidden[N];

int main() {
  scanf("%d", &n);
  scanf(" %s", str);
  s = (string) str;
  reverse(s.begin(), s.end());
  s += "$";
  n = s.size();
  suff_arr();
  lcp();
  ll bst = 0;
  n--;
  for(int i = 1; i <= n; ++i) {
    scanf("%1d", a + (n - i + 1));
    if(a[n - i + 1] == 0) bst = i;
  }
  for(int i = 1; i <= n; ++i) forbidden[i] = a[r[i] + 1];
  for(int i = 1; i <= n; ++i) forbidden[i] += forbidden[i - 1];
  esq[0] = -1;
  for(int i = 1; i <= n; ++i) {
    esq[i] = i - 1;
    while(esq[i] >= 0  && h[esq[i]] >= h[i] ) esq[i] =  esq[esq[i]];
  }
  dir[n] = n + 1;
  for(int i = n - 1; i >= 1; --i) {
    dir[i] = i + 1;
    while( dir[i] <= n && h[dir[i]] >= h[i] ) dir[i] = dir[dir[i]];
  }
  for(int i = 1; i <= n; ++i) {
    int l = max(esq[i], 0);
    int r = min(dir[i], n);
    int qtd = (r - l) - (forbidden[r] - forbidden[l]);
    bst = max(bst, qtd * (ll)(h[i]));
  }
  printf("%lld\n", bst);
  return 0;
}