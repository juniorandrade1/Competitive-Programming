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

const int N = 10010;

int n;
vi divisors;
int v[N];
int inv[N];

void goDivisors() {
  for(int i = 1; i <= n; ++i) {
    if(n % i == 0) divisors.pb(i);
  }
}


ll solve(int k) {
  ll foo = 0;
  for(int i = 0; i < n; i += k) {
    for(int j = 0; j < k; ++j) {
    }
  }
  return foo;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i), v[i]--, inv[v[i]] = i;
  goDivisors();
  
  ll ans = LINF, idx = -1;
  for(int i = 0; i < divisors.size(); ++i) {
    if(solve(divisors[i]) < ans) {
      ans = solve(divisors[i]);
      idx = divisors[i];
    }
  }
  printf("%d %d\n", idx, ans);
  return 0;
}