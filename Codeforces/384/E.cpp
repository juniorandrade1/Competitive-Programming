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

const int N = 1010;

int n;
int v[N];
int pd[N][1 << 8];
vi g[8];
int qtd;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", v + i);
    v[i]--;
    g[v[i]].pb(i);
  }
  int ans = 0;
  for(int i = 1; i < n; ++i) {
    memset(pd, -1, sizeof pd);
    qtd = i;
    for(int j = 0; j < 8; ++j) {
    }
  }


  return 0;
}