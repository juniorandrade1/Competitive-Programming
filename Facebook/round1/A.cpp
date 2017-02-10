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

const int N = 301;

int n, m;
ll c[N][N];
ll pd[N][N];

ll func(int pos, int qtd) {
  if(qtd < pos) return LINF;
  if(qtd >= n) return 0;
  if(pd[pos][qtd] != -1) return pd[pos][qtd];
  ll ret = func(pos + 1, qtd);
  ll sum = 0;
  for(int i = 0; i < m; ++i) {
    ll p = (ll)(i + 1) * (ll)(i + 1);
    sum += c[pos][i];
    ret = min(ret, func(pos + 1, qtd + i + 1) + sum + p);
  }
  return pd[pos][qtd] = ret;
}

inline void main2() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) scanf("%lld", &c[i][j]);
    sort(c[i], c[i] + m);
  }
  memset(pd, -1, sizeof pd);
  printf(" %lld\n", func(0, 0));
}

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}