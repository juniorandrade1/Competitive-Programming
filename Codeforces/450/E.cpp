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

const int N = 100010;

struct Node {
  int a, b;
  Node() {
    a = -INF;
    b = INF;
  }
  Node(int _a, int _b) {
    a = _a;
    b = _b;
  }
  
};

Node join(Node a, Node b) {
  if(a.a != b.a) {
    if(a.a > b.a) return a;
    else return b;
  }
  else {
    if(a.b < b.b) return a;
    return b;
  }
}

int n;
char s[N];
int t;

inline int getVal(char c) {
  if(c == 'a') return 0;
  if(c == 'b') return 1;
  return 2;
}

ii pd[N][2];
short memo[N][2];
int csum[N];

ii func(int pos, int op) {
  if(pos >= n) return ii(0, 0);
  if(memo[pos][op]) return pd[pos][op];
  memo[pos][op] = 1;
  ii sol = ii(0, 0);
  int o = getVal(s[pos]);
  if(o == 2 || o == op) {
    sol = func(pos + 2, op);
    sol.F++;
    sol.S += (o == 3);
  }
  return pd[pos][op] = sol;
}

Node all[N];

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  scanf("%d", &t);
  for(int i = 0; i < n; ++i) {
    csum[i + 1] = csum[i];
    csum[i + 1] += (s[i] == '?');
    all[i] = Node(0, 0);
  }
  int needB = t / 2;
  int needA = t - needB;
  Node at = Node();
  for(int i = 0; i + t - 1 < n; ++i) {
    ii a = func(i, 0);
    ii b = func(i + 1, 1);
    at = join(at, all[i]);
    if(a.F >= needA && b.F >= needB) {
      Node ax = at;
      ax.a++;
      ax.b += (csum[i + t] - csum[i]);
      all[i + t] = join(all[i], ax);
    }
  }
  for(int i = 0; i <= n; ++i) at = join(at, all[i]);
  printf("%d\n", at.b);
  return 0;
}