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

const int N = 1e2 + 10;

int n;
char s[N];
int pd[N][26];

int func(int pos, int alpha) {
  if(alpha == 26) return 0;
  if(pos == n) return 26 - alpha;
  if(pd[pos][alpha] != -1) return pd[pos][alpha];
  int ret = func(pos + 1, alpha);
  if(s[pos] - 'a' == alpha) ret = min(ret, func(pos + 1, alpha + 1));
  else ret = min(ret, 1 + func(pos, alpha + 1));
  return pd[pos][alpha] = ret;
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(0, 0));
  return 0;
}