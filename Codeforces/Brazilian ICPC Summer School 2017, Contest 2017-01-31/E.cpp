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

vi zFunction(string s) {
  int n = s.size();
  vi z(n);

  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    } else {
      int k = i-L;
      if (z[k] < R-i+1) z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      }
    }
  }
  return z;
}

string s, t;
int k;
vi za, zb;

int main() {
  //arquivo();
  cin >> s >> t;
  cin >> k;
  string ts = t + "$" + s;
  za = zFunction(ts);
  int sLen = s.size();
  int tLen = t.size();
  int n = ts.size();
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  string rts = t + "$" + s;
  zb = zFunction(rts);
  reverse(zb.begin() + tLen + 1, zb.end());
  vi sol;
  for(int i = tLen + 1; i + tLen <= n; ++i) {
    if(tLen - za[i] - zb[i + tLen - 1] <= k) {
      sol.pb(i - tLen);
    }
  }
  printf("%d\n", (int)sol.size());
  for(int i = 0; i < sol.size(); ++i) {
    printf("%lld ", sol[i]);
  }
  printf("\n");

  return 0;
}