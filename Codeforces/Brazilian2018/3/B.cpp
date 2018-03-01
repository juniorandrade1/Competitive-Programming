
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

#define pi acos(-1.0)

const int N = 251;

ll a, b, c;
int n, m;
ll v[N][N];
ll f[N * N];
map< int, ll > qtd;
int sol[N * N];

int main() {
  scanf("%lld %lld %lld %lld", &f[1], &a, &b, &c);
  for(int i = 2; i < N * N; ++i) f[i] = ((a * f[i - 1] + b) % c) + 1;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      scanf("%lld", &v[i][j]);
      qtd[v[i][j]]++;
    }
  }
  int days = qtd.size();
  vii ax;
  for(int i = 1; i <= days; ++i) ax.pb(mp(f[i], i));
  sort(ax.begin(), ax.end());
  vii br;
  for(map< int, ll > :: iterator it = qtd.begin(); it != qtd.end(); it++) br.pb(mp(it->S, it->F));
  sort(br.begin(), br.end());
  for(int i = 0; i < days; ++i) sol[ax[i].S] = br[i].S;
  printf("%d\n", days);
  for(int i = 1; i <= days; ++i) {
    if(i != 1) printf(" ");
    printf("%d", sol[i]);
  }
  printf("\n");
  return 0;
}