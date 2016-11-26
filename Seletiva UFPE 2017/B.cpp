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
#include <queue>

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

const int N = 2000101;

int n;
int v[N][25];
char s[25];
int ans = 0;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    int len = strlen(s);
    int num = 0;
    for(int j = 0; j < len; ++j) {
      num *= 2;
      num += s[j] - '0';
      v[num][j]++;
    }
  }
  if(n == 1) {
    puts("1");
    return 0;
  }
  queue< ii > q; q.push(mp(0, 0));
  while(!q.empty()) {
    ii foo = q.front(); q.pop();
    int x = foo.F, qtd = foo.S;
    if(x > 2000000) continue;
    ans += 2;
    int a = x * 2;
     int b = x * 2 + 1;
    if(v[a][qtd] >= 2) q.push(mp(a, qtd + 1));
    if(v[b][qtd] >= 2) q.push(mp(b, qtd + 1));
  }
  printf("%d\n", ans + 1);
  return 0;
}