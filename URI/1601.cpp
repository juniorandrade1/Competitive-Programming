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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 101;

int n;
ll c[N];
ll calc[N][N];

int main() {
  //arquivo();
  while(scanf("%d", &n) != EOF) {
    memset(c, 0, sizeof c);
    for(int i = 1; i <= n; ++i) {
      int x; scanf("%d", &x);
      c[x]++;
    }
    for(int i = 1; i < N; ++i) {
      ll qtd = 0;
      for(int j = i; j < N; ++j) {
        qtd += c[j];
        if(i == j) calc[i][j] = 0;
        else calc[i][j] = calc[i][j - 1] + qtd;
      }
    }

    ll ans = LINF;
    for(int i = 1; i < N; ++i) {
      ans = min(ans, calc[1][i] + calc[i + 1][n]);
    }
    ll countI = 0;
    for(int i = 1; i < N; ++i) {
      countI += c[i];
      for(int j = i + 1; j + 1 < N; ++j) {
        ll s1 = calc[1][i];
        ll s2 = calc[i + 1][j];
        ll s3 = 0;
        ll qtd = countI;
        ll sum = 0;
        for(int k = j + 1; k < N; ++k) {
          qtd += c[k];
          if(k == j + 1) sum += (k - i) * qtd;
          else sum += qtd;
          s3 += sum;
        }
        ans = min(ans, s1 + s2 + s3);
      }
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}