#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

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
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 18;

ll md = (int)1e9 + 7LL;

inline ll addMod(ll a, ll b) { 
  a += b;
  while(a >= md) a -= md;
  return a;
}

inline ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}

ll pd[1 << N];
int n, m;
int ini[N];
ll v[N];

ll func(int mask) {
  if(((1 << n) - 1) == mask) return 1;
  if(pd[mask] != -1) return pd[mask];
  ll ret = 0;
  for(int i = 0; i < n; ++i) {
    if((mask >> i) & 1) continue;
    int foo = (ini[i] & mask);
    if(foo) continue;
    ret = addMod(ret, mulMod(v[i], func(mask | (1 << i))));
  }
  return pd[mask] = ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  while(m--) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    ini[b] |= (1 << a);
  }
  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(0));
  return 0;
}