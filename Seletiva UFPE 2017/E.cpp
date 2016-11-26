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

const int N = 500;

double p[N], t[N];
int n, m;
double ans[N];
double atP = 1.0;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf("%lf", p + i);
  for(int i = 0; i < n; ++i) scanf("%lf", t + i);
  while(m--) {
    for(int i = 0; i < n; ++i) {
      ans[i] += atP * (1.0 - p[i]);
      atP *= p[i];
      p[i] *= (1.0 - t[i]);
    }
  }
  for(int i = 0; i < n; ++i) printf("%.10lf ", ans[i]);
    printf("\n");
  return 0;
}