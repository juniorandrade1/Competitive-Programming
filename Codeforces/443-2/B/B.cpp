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

const int N = 505;

int n;
ll k;
deque< ii > q;

int main() {
  scanf("%d %lld", &n, &k);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    q.push_back(ii(x, 0));
  }
  int lstPower = 0, qtdPower = 0;
  while(qtdPower < n) {
    ii f1 = q.front(); q.pop_front();
    ii f2 = q.front(); q.pop_front();
    if(f1.F < f2.F) swap(f1, f2);
    if(f1.F == lstPower) qtdPower++;
    else {
      lstPower = f1.F;
      qtdPower = 1;
    }
    f1.S++;
    if(f1.S >= k) {
      printf("%lld", f1.F);
      return 0;
    }
    q.push_back(f2);
    q.push_front(f1);
  }
  printf("%lld\n", q.front().F);
  return 0;
}