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

const int N = 500000;

char s[22];
vi sol;

void back(int l, int r, int len) {
  if(r < l) {
    ll foo = 0;
    for(int i = 0; i < len; ++i) foo *= 10LL, foo += s[i] - '0';
    sol.pb(foo);
    return;
  }
  for(int i = 0; i < 10; ++i) {
    if(i == 0 && l == 0) continue;
    s[l] = s[r] = i + '0';
    back(l + 1, r - 1, len);
  }
}

int main() {
  for(int i = 0; i < 11; ++i) back(0, i, i + 1);
  sort(sol.begin(), sol.end());
  int q; scanf("%d", &q);
  while(q--) {
    ll l, r; scanf("%lld %lld", &l, &r);
    vi :: iterator it1 = lower_bound(sol.begin(), sol.end(), l), it2 = lower_bound(sol.begin(), sol.end(), r);
    if(*it2 > r) it2--;
    if(*it1 > r) puts("0 -1 -1");
    else printf("%lld %lld %lld\n",(long long)(it2-it1) + 1, *it1, *it2);
  }
  return 0;
}