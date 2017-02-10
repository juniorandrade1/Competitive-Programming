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
#define PI acos(-1.0)
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1010;
const int md = (ll)1e9 + 7LL;

inline ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

int a[26];
int n;
char s[N];
int ok[N][N];
int pd[N];

int f1(int pos) {
  if(pos == n) return 1;
  if(pd[pos] != -1) return pd[pos];
  ll ret = 0;
  for(int i = pos; i < n; ++i) {
    if(ok[pos][i] == 0) break;
    ret = addMod(ret, f1(i + 1));
  }
  return pd[pos] = ret;
}

int f2(int pos) {
  if(pos == n) return 0;
  if(pd[pos] != -1) return pd[pos];
  int ret = 0;
  for(int i = pos; i < n; ++i) {
    if(ok[pos][i] == 0) break;
    ret = max(ret, max(f2(i + 1), i - pos + 1));
  }
  return pd[pos] = ret;
}

int f3(int pos) {
  if(pos == n) return 0;
  if(pd[pos] != -1) return pd[pos];
  int ret = INF;
  for(int i = pos; i < n; ++i) {
    if(ok[pos][i] == 0) break;
    ret = min(ret, 1 + f3(i + 1));
  }
  return pd[pos] = ret;
}

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  for(int i = 0; i < 26; ++i) scanf("%d", a + i);
  for(int i = 0; i < n; ++i) {
    set<int>app;
    for(int j = i; j < n; ++j) {
      app.insert(s[j] - 'a');
      int l = j - i + 1;
      ok[i][j] = 1;
      for(set<int>::iterator it = app.begin(); it != app.end(); it++) if(a[*it] < l) {
        ok[i][j] = 0;
        break;
      }
      if(ok[i][j] == 0) break;
    }
  }
  memset(pd, -1, sizeof pd);
  printf("%d\n", f1(0));
  memset(pd, -1, sizeof pd);
  printf("%d\n", f2(0));
  memset(pd, -1, sizeof pd);
  printf("%d\n", f3(0));
  return 0;
}