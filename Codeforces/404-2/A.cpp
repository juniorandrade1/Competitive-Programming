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

const int N = 1e5 + 10;


map<string, ll> cnt;
char s[200000];

int main() {
  cnt["Tetrahedron"] = 4;
  cnt["Cube"] = 6;
  cnt["Octahedron"] = 8;
  cnt["Dodecahedron"] = 12;
  cnt["Icosahedron"] = 20;

  int n; scanf("%d", &n);
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    ans += cnt[(string)s];
  }
  printf("%lld\n", ans);
  return 0;
}