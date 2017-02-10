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

int n, t1, t2;


void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}


int main() {
  arquivo();
  scanf("%d %d %d", &n, &t1, &t2);
  ll lo = 0, hi = 12345678910;
  while(lo < hi) {
    ll mid = (lo + hi) >> 1;
    if(mid / t1 + mid / t2 < n) lo = mid + 1;
    else hi = mid;
  }
  ll qtd = lo / t1 + lo / t2;
  if(lo % t1) {
    lo += (t1 - (lo % t1));
    qtd++;
  }
  else if(lo % t2) {
    lo += (t2 - (lo % t2));
    qtd++;
  }

  printf("%lld %lld\n", qtd, lo);

  return 0;
}