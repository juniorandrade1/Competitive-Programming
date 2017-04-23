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

const int N = 100010;

int n;
ll a[N], b[N];
int o[N];
ll sumA, sumB;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", a + i), sumA += a[i];
  for(int i = 0; i < n; ++i) scanf("%lld", b + i), sumB += b[i];
  srand(2389739821);
  for(int i = 0; i < n; ++i) o[i] = i;
  while(1) {
    ll sA = 0, sB = 0;
    for(int i = 0; i < n / 2 + 1; ++i) {
      int num = (rand() % (n - i)) + i;
      swap(o[i], o[num]);
      sA += a[o[i]], sB += b[o[i]];
    }
    if(sA * 2 > sumA && sB * 2 > sumB) {
      printf("%d\n", n / 2 + 1);
      for(int i = 0; i < n / 2 + 1; ++i) printf("%d ", o[i] + 1);
      printf("\n");
      break;
    }
  }
  return 0;
}