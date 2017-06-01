#include <bits/stdc++.h>

#define maxn 200100
#define sq 333
#define logn 23
#define inf 0x3F3F3F3F
#define linf 0x3F3F3F3F3F3F3F3FLL
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define mod 1000000007LL

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef priority_queue<pii, vii, greater<pii> > pq;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

ll x;
int t;
ll a;

ll f(ll n) {
  ll aux = (2 * x - (n * n) + n);
  if(aux <= 0) return -1;
  if(aux % (2*n) == 0) return aux / (2*n);
  else return -1;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%lld", &x);
    ll ans = -1;
    for(ll i = 2; i <= 40000; ++i) {
      a = f(i);
      if(a > 0) {
        ans = i;
        break;
      }
    }
    if(ans == -1) {
      printf("IMPOSSIVEL\n");
    } else {
      printf("%lld = %lld", x, a);
      for(ll i = 1; i <= ans-1; ++i) {
        printf(" + %lld", a + i);
      }
      printf("\n");
    }
  }

  return 0;
}