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

map< string, int > id;
map< int, string > vlt;
int idx = 0;

int n, m;
char s1[N], s2[N];

inline int getId(string s) {
  if(id.find(s) == id.end()) {
    id[s] = idx;
    vlt[idx++] = s;
  }
  return id[s];
}

vi g[N];
int vis[N];
int comp = 1;
int sz;
int lenComp[N];

void dfs(int x) {
  vis[x] = comp;
  sz++;
  for(int i = 0; i < g[x].size(); ++i) if(!vis[g[x][i]]) dfs(g[x][i]);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s %s", s1, s2);
    g[getId((string)s1)].pb(getId((string)s2));
    g[getId((string)s2)].pb(getId((string)s1));
  }
  for(int i = 0; i < idx; ++i) {
    if(vis[i] == 0) {
      sz = 0;
      dfs(i);
      lenComp[comp] = sz;
      comp++;
    }
  }

  scanf(" %d", &m);
  while(m--) {
    scanf(" %s", s1);
    int l = getId((string)s1);
    puts(lenComp[vis[l]] & 1 ? "N": "S");
  }
  return 0;
}