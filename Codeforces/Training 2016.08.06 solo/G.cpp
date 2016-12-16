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

const int N = 200020;

int k, n;
int c[N];
vii foo;
int sol[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", c + i);
    foo.pb(mp(c[i], i));
  }
  sort(foo.begin(), foo.end());
  for(int i = 0; i < n; ++i) {
    int id = foo[i].S, x = foo[i].F;
    int mini = min(x, k);
    k -= mini;
    sol[id] = mini;
  }
  for(int i = 0 ; i < n; ++i) {
    if(i) printf(" ");
    printf("%d", sol[i]);
  }
  printf("\n");
  return 0;
}