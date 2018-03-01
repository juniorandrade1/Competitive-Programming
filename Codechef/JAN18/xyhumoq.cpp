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

const int N = 35;
const int M = 1000001;


char s[N];
map< int, int > memo[N][N];
map< int, int > pd[N][N];
int n, x;
int testCase = 1;

ll calcDp[N][N];

ll calc(ll q0, ll q1) {
  if(calcDp[q0][q1] != -1) return calcDp[q0][q1];
  if(q0 == 0 || q1 == 0) return 1;
  ll ret = 0;
  for(int i = 1; i <= q1; ++i) ret += calc(i - 1, q1 - 1);
  return calcDp[q0][q1] = ret;
}

int func(int pos, int q0, int q1, int qtd) {
  if(qtd < 0) return INF;
  if(pos == n - 1) return calc(q0 + 1, q1) == qtd;
  if(memo[pos][q1][qtd] == testCase) return pd[pos][q1][qtd];
  memo[pos][q1][qtd] = testCase;
  int v = s[pos] - '0';
  int ret = (v == 0) + func(pos + 1, q0, q1 + 1, qtd);
  ret = min(ret, (v == 1) + func(pos + 1, q0 + 1, q1, qtd - calc(q0 + 1, q1)));
  return pd[pos][q1][qtd] = ret;
}

inline void main2() {
  scanf(" %s", s);
  scanf("%d", &x);
  n = strlen(s);
  int ans = func(1, 0, 1, x);
  if(ans >= INF) printf("NO\n");
  else printf("YES\n%d\n", ans);
  testCase++;
  return;
}

int main() {
  memset(calcDp, -1, sizeof calcDp);
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}