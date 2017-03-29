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

inline ll trueABS(ll a) {
  return (a < 0) ? -a : a;
}

map<ll, bool> rep;
map<ll, bool> cant;

ll b1, q, l, n;
ll v[N];

int main() {
  scanf("%lld %lld %lld %lld", &b1, &q, &l, &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", v + i);
    cant[v[i]] = 1;
  }
  if(trueABS(b1) > l) puts("0");
  else if(q == 0 || b1 == 0) {
    int ans = (1 - cant[b1]);
    if(cant[0]) printf("%d\n", ans);
    else puts("inf");
  }
  else if(q == -1) {
    if(cant[b1] && cant[-b1]) puts("0");
    else puts("inf");
  }
  else {
    int ans = 0;
    while(trueABS(b1) <= l) {
      if(rep[b1]) {
        if(cant[b1]) printf("%d\n", ans);
        else puts("inf");
        exit(0);
      }
      rep[b1] = 1;
      ans += (1 - cant[b1]);
      b1 *= q;
    }
    printf("%d\n", ans);
  }
  return 0;
}