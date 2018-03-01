#include <bits/stdc++.h>
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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pi acos(-1.0)
#define eps 1e-9

const int N = 50010;

int n, m;
vi g[N];
int dfsNum[N], dfsLow[N], dfsCounter = 1, Stack[N], sp = 0, inStack[N], componentSize[N], component = 0;

void push(int x) {
  inStack[x] = 1;
  Stack[sp++] = x;
}

void pop() {
  inStack[Stack[sp - 1]] = 0;
  sp--;
}

void clear() {
  while(sp) {
    inStack[Stack[sp - 1]] = 0;
    sp--;
  }
}

int top() {
  return Stack[sp - 1];
}

void tarjan(int x, int ult) {
  dfsNum[x] = dfsLow[x] = dfsCounter++;
  push(x);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    if(dfsNum[y] == 0) {
      tarjan(y, x);
      dfsLow[x] = min(dfsLow[x], dfsLow[y]);
      if(dfsNum[x] <= dfsLow[y]) {
        int foo;
        do {
          foo = top(); pop();
          componentSize[component]++;
        }
        while(foo != y);
        component++;
      }
    }
    else if(inStack[y]) dfsLow[x] = min(dfsLow[x], dfsNum[y]);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    g[a - 1].pb(b - 1);
    g[b - 1].pb(a - 1);
  }
  tarjan(0, 0);
  printf("%d\n", *max_element(componentSize, componentSize + component) + 1);
  return 0;
}