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

int n;
int a[N];
int tot = 0;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", a + i), tot += a[i], a[i] += a[i - 1];
  if(tot) {
    puts("YES");
    puts("1");
    printf("%d %d\n", 1, n);
    exit(0);
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] && tot - a[i]) {
      printf("YES\n");
      printf("2\n");
      printf("%d %d\n%d %d\n", 1, i, i + 1, n);
      exit(0);
    }
  }

  puts("NO");

  return 0;
}