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

const int N = 123456;

ll v[N];
int n;

inline void main2() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", v + i);
    v[i] += v[i - 1];
  }
  ll as = v[n];
  ll s = LINF;
  ll idx = -1;
  for(int i = 1; i <= n; ++i) {
    ll at = as - v[i - 1] + v[i];
    if(at < s) {
      s = at;
      idx = i;  
    }
  }
  printf("%lld\n", idx);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}