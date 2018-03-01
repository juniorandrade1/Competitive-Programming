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

const int N = 50021;
const int M = 220;
const int MOD = (1e9 + 7LL);

ll C[M][M];
ll S[N][M];

int main() {
  C[0][0] = 1;
  for(int i = 1; i < M; ++i) for(int j = 0; j <= i; ++j) {
    if(j == 0 || j == i) C[i][j] = 1;
    else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    if(C[i][j] >= MOD) C[i][j] -= MOD;
  }
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j <= min(i, M - 1); ++j) {
      if(j == i) S[i][j] = 1;
      else if(j == 0) S[i][j] = 0;
      else {
        S[i][j] = S[i - 1][j - 1] + S[i - 1][j] * (ll)(i - 1);
        S[i][j] %= MOD;
      }
    }
  }
  int t; scanf("%d", &t);
  while(t--) {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    if(a + b - 1 > n) {
      puts("0");
      continue;
    }
    if(n == 1) {
      if(a == 1 && b == 1) puts("1");
      else puts("0");
      continue;
    }
    ll sol = (ll)S[n - 1][a + b - 2] * (ll)C[a + b - 2][b - 1];
    sol %= MOD;
    printf("%lld\n", sol);  
  }
  return 0;
} 