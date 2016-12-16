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

const int N = 500000;

int n;
vii s;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  ll sum = 0;
  for(int i = 0; i < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    sum += a;
    s.pb(mp(a, -1));
    s.pb(mp(b, 1));
  }
  sort(s.begin(), s.end());
  ll qtd = 0;
  ll maxi = sum;
  ll p = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i].S == -1) {
      qtd -= s[i].S;
      sum -= s[i].F;
    }
    ll foo = qtd * (ll)s[i].F + sum;
    if(foo > maxi) {
      maxi = foo;
      p = s[i].F;
    }
    if(s[i].S == 1) qtd -= s[i].S;
  }
  printf("%lld %lld\n", p, maxi);
  return 0;
}