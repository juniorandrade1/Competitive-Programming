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

const int N = 5002;

int testCase = 1;
int dp[N][N][2];
int memo[N][N][2];
int n, m;
char s[N], t[N];

int solve(int ps, int pt, int lt) {
  if(ps == n && pt == m) return 0;
  if(memo[ps][pt][lt] == testCase) return dp[ps][pt][lt];
  memo[ps][pt][lt] = testCase;
  int ret = INF;
  char lstChar = (lt == 0) ? s[ps - 1] : t[pt - 1];
  if(ps < n) ret = min(ret, solve(ps + 1, pt, 0) + (lstChar != s[ps]));
  if(pt < m) ret = min(ret, solve(ps, pt + 1, 1) + (lstChar != t[pt]));
  return dp[ps][pt][lt] = ret;
}

inline void main2() {
  scanf("%d %d", &n, &m);
  scanf(" %s %s", s, t);
  printf("%d\n", 1 + min(solve(1, 0, 0), solve(0, 1, 1)));
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2(), testCase++;
  return 0;
}