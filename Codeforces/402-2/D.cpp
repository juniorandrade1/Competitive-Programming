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

const int N = 2 * (ll)(1e5) + 10;

char s[N], t[N];
int ls, lt;
int p[N];
bitset<N>marc;

inline bool test(int nop) {
  marc.reset();
  for(int i = 0; i < nop; ++i) marc[p[i] - 1] = 1;
  int ps, pt;
  ps = pt = 0;
  while(ps < ls && pt < lt) {
    if(marc[ps] == 0 && s[ps] == t[pt]) pt++;
    ps++;
  }
  return lt == pt;
}

int main() {
  scanf(" %s %s", s, t);
  ls = strlen(s);
  lt = strlen(t);
  for(int i = 0; i < ls; ++i) scanf("%d", p + i);
  int lo = 0, hi = ls;
  while(lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if(!test(mid)) hi = mid - 1;
    else lo = mid;
  }
  printf("%d\n", lo);
  return 0;
}