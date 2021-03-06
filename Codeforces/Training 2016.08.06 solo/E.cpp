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

const int N = 101;

int n, m;
ll arr[N];
vi solution;


int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    int k; scanf("%d", &k);
    ll lol = 0;
    while(k--) {
      int x;
      scanf("%d", &x);
      arr[x] |= (1 << i);
    }
  }
  int res = n + 1, mask = 0;
  for (int i = 1; i < (1 << n); i++) {
    int j;
    for (j = 1; j <= m; j++) if (!(i & arr[j])) break;
    int c = __builtin_popcount(i);
    if (j > m && res > c) res = c, mask = i;
  }
  printf("%d\n", res);
  for(int i = 0; i < n; ++i) if((mask >> i) & 1) printf("%d ", i + 1);
  printf("\n");
  return 0;
}