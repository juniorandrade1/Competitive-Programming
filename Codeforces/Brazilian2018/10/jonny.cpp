#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 11;

ll n, m, b[N];
set< ll > s;


inline void back(ll x) {
  if(s.find(x) != s.end()) return;
  s.insert(x);
  for(int i = 0; i < n; ++i) back(x / b[i]);
}

int main() {
  scanf("%lld %lld", &m, &n);
  for(int i = 0; i < n; ++i) scanf("%lld", b + i);
  back(m);
  printf("%d\n", (int)s.size());
  return 0;
} 
