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

const int N = 100010;

int n;
ll v[N];
ll s[N];

int main() {
  freopen("hell.in", "r", stdin);
  freopen("hell.out", "w", stdout);
  scanf("%d", &n);
  ll sum = 0;
  for(int i = 0; i < n; ++i) scanf("%lld", v + i), sum += v[i];
  if(sum & 1) {
    puts("No");
    return 0;
  }
  sum >>= 1;
  for(int i = n - 1; i >= 0; --i) {
    s[i] = (sum >= v[i]) ? 1 : -1;
    if(sum >= v[i]) sum -= v[i];
  }
  if(sum) puts("No");
  else {
    puts("Yes");
    for(int i = 0; i < n; ++i) {
      if(i) printf(" ");
      printf("%lld", s[i]);
    }
    printf("\n");
  }
  return 0;
}