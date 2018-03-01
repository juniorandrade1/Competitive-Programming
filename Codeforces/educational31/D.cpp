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

const int N = 100010;

int n;
priority_queue< ll > q;
ll totSum = 0;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    q.push(-x);
  }
  if(n == 1) {
    puts("0");
    return 0;
  }
  ll ans = 0;
  if(n % 2 == 0) {
    ll f1 = -q.top(); q.pop();
    ll f2 = -q.top(); q.pop();
    ans += f1 + f2;
    q.push(-(f1 + f2));
  }
  while(q.size() > 1) {
    ll f1 = -q.top(); q.pop();
    ll f2 = -q.top(); q.pop();
    ll f3 = -q.top(); q.pop();
    ans += f1 + f2 + f3;
    q.push(-(f1 + f2 + f3));
  }
  printf("%lld\n", ans);
  return 0;
}