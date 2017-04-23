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

const int N = 10000001;

int is[N];

inline void sieve() {
  is[1] = 1;
  for(int i = 2; i < N; ++i) {
    if(!is[i]) for(int j = 1; j * i < N; ++j) is[i * j] = i;
  }
}

vii factorization;
map<int, ll> qtdUsed;
ll revCalc[100];

inline void solve(int pos) {
  if(pos == factorization.size()) return;
  for(int i = 0; i <= factorization[pos].S; ++i) {
    qtdUsed[factorization[pos].F] += i * revCalc[pos + 1];
    solve(pos + 1);
  }
}

int main() {
  sieve();
  int n; 
  while(scanf("%d", &n) != EOF && n) {
    factorization.clear();
    qtdUsed.clear();
    if(n == 1) puts("1");
    else {  
      vi f;
      while(n > 1) {
        f.pb(is[n]);
        n /= is[n];
      }
      sort(f.begin(), f.end());
      for(int i = 0; i < f.size();) {
        int j = i;
        while(j < f.size() && f[i] == f[j]) j++;
        factorization.pb(mp(f[i], j - i));
        i = j;
      }
      revCalc[factorization.size()] = 1;
      for(int i = (int)factorization.size() - 1; i >= 0; --i) revCalc[i] = revCalc[i + 1] * (factorization[i].S + 1);
      solve(0);
      ll ans = 1;
      for(int i = 0; i < factorization.size(); ++i) ans *= (qtdUsed[factorization[i].F] + 1LL);
      printf("%lld\n", ans);
    }
  }
  return 0;
}