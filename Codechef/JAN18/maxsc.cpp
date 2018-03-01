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

const int N = 700 + 10;

int n;
ll v[N][N];
ll dp[N][N];

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%lld", &v[i][j]);
    }
    sort(v[i], v[i] + n);
  }
  for(int i = 0; i < n; ++i) dp[0][i] = v[0][i];
  for(int i = 1; i < n; ++i) {
    int k = 0;
    ll bst = -LINF;
    for(int j = 0; j < n; ++j) {
      while(k < n && v[i - 1][k] < v[i][j]) {
        bst = max(bst, dp[i - 1][k]);
        k++;
      }
      dp[i][j] = v[i][j] + bst;
    }
  }
  if(dp[n - 1][n - 1] < 0) dp[n - 1][n - 1] = -1;
  printf("%lld\n", dp[n - 1][n - 1]);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}