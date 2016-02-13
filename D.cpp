#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 1000010;
#define LOG_TWO_N 20

int n, m;
int v[N];

inline bool go(ll top) {
  int g = 1;
  ll maxi = v[0];
  ll ult = 0;
  for(int i = 0; i < n; ++i) {
    if( v[i] > top ) return false;
    maxi = max( maxi, (ll)v[i] );
    ll vaue = (i - ult + 1) * 1ll * maxi;
    if( vaue > top ) {
      g++;
      maxi = v[i];
      ult = i;
    }
  }
  return g <= m;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", v + i);
    ll lo = 0, hi = 1000000000000000LL;
    while(lo < hi) {
      ll mid = (lo + hi) >> 1LL;
      if( go(mid) ) hi = mid;
      else lo = mid + 1;
    }
    printf("%lld\n", lo);
  }
  return 0;
}
