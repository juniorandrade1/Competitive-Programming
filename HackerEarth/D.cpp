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

const int N = 501;
const int M = 9;

 #define getcx getchar_unlocked

 inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }   

int n;
ll k;
ll v[N];
int lca[N][M];
int h[N];

int go(int a, int b) {
  if(h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b];
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) a = lca[a][i];
  if(a == b) return lca[a][0];
  for(int i = M - 1; i >= 0; --i) if(lca[a][i] != lca[b][i]) a = lca[a][i], b = lca[b][i];
  return lca[a][0];
}

int x;

int main() {
  scanf("%d %lld", &n, &k);
  for(int i = 1; i <= n; ++i) inp(x), v[i] = x;
  for(int i = 2; i <= n; ++i) inp(lca[i][0]), h[i] = h[lca[i][0]] + 1;
  for(int i = 1; i <= n; ++i) for(int j = 1; j < M; ++j) lca[i][j] = lca[lca[i][j - 1]][j - 1];
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      int anc = go(i, j);
      while(anc) {
        ans += ((v[i] + v[j] + v[anc]) >= k);
        anc = lca[anc][0];
      }
    }
  }
  printf("%d\n", ans);
 
  return 0;
}