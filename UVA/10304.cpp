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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 251;

int pd[N][N];
int memo[N][N];
int test = 1;
int n;
int v[N], s[N];

int func(int l, int r) {
  if(l > r) return 0;
  if(memo[l][r] == test) return pd[l][r];
  int ret = INF;
  for(int i = l; i <= r; ++i) ret = min(ret, func(l, i - 1) + func(i + 1, r) + s[r] - s[l - 1] - v[i]);
  memo[l][r] = test;
  return pd[l][r] = ret;
}

int main() {
  //arquivo();
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; ++i) {
      scanf("%d", v + i);
      s[i] = s[i - 1] + v[i];
    }
    printf("%d\n", func(1, n));
    test++;
  }

 
  return 0;
}