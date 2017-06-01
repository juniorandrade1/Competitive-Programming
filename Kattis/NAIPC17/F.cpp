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

const int N = 360;

int n;
ll k;

ll C[N][N];

inline void preProcess() {
  C[0][0] = 1;
  for(int i = 1; i < N; ++i) for(int j = 1; j <= i; ++j) C[i][j] = (i == j) ? 1 : C[i - 1][j] + C[i - 1][j - 1];
}

inline ll calcMax() {
  ll tp = 26;
  ll ans = 1;
  ll tot = (k * (k + 1)) / 2LL;
  for(int i = 1; i <= k; ++i) {
    ans *= (C[tot][i] * tp);
    tot -= i;
    tp--;
  }
  return ans;
}

int main() {
  preProcess();
  scanf("%lld %d", &k, &n);
  ll maxTot = calcMax();
  if(maxTot < n) puts("-1");
  else {
    
  } 
  return 0;
}