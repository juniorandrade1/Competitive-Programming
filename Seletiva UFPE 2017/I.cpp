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
typedef pair< int, int > ii;
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

const int N = 100010;
const int M = 1010;

vector< ii > aux[N];

void kmp(const string &needle, const string &haystack, int ind) {
  int m = needle.size();
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and needle[border[i+1]] != needle[i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }

  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > -1 and needle[seen] != haystack[i]) {
      seen = border[seen];
    }
    if (++seen == m) {
      aux[i - m + 1].pb(mp(i, ind));
      seen = border[m]; // There are no more characters in needle, so with the next input character let's try with the border of the whole needle.
    }
  }
}

char s[N], p[N];
int n;
ll val[N];
ll pd[N];

ll func(int pos) {
  if(pos == n) return 0;
  if(pd[pos] != -1) return pd[pos];
  ll ret = func(pos + 1);
  for(int i = 0; i < aux[pos].size(); ++i) {
    ret = max(ret, func(aux[pos][i].F + 1) + aux[pos][i].S);
  }
  return pd[pos] = ret;
}

int main() {
  scanf(" %s", s);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s %lld", p, val + i);
    kmp((string)p, (string)s, val[i]);
  }
  n = strlen(s);
  memset(pd, -1, sizeof pd);
  for(int i = n - 1; i >= 0; --i) func(i);
  printf("%lld\n", func(0));
  return 0;
}