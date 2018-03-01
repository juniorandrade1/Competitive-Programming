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

const int N = 200010;

struct Node {
  int F, S, T;
  Node(){};
  Node(int FF, int SS, int TT) {
    F = FF;
    S = SS;
    T = TT;
  }
  bool operator < (Node other) const {
    return F < other.F;
  }
  void print() {
    printf("-> idx = %d val = %d len = %d\n", F, S, T);
  }
};

int n;
int v[N];
set< ii > mxs;
set< Node > idx;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  for(int i = 1; i <= n;) {
    int j = i;
    while(j <= n && v[i] == v[j]) j++;
    mxs.insert(ii(-(j - i), i));
    idx.insert(Node(i, v[i], j - i));
    i = j;
  }
  int ans = 0;
  while(mxs.size()) {
    ans++;
    ii foo = *mxs.begin(); mxs.erase(mxs.begin());
    int sz = -foo.F, l = foo.S;
    set< Node >:: iterator sl = idx.lower_bound(Node(l, 0, 0)); 
    set< Node >:: iterator sr = idx.upper_bound(Node(l, 0, 0));
    if(sl != idx.begin() && sr != idx.end()) {
      sl--;
      Node al = *sl;
      Node ar = *sr;
      if(sl->S == sr->S) {
        mxs.erase(ii(-al.T, al.F));
        mxs.erase(ii(-ar.T, ar.F));
        mxs.insert(ii(-(al.T + ar.T), al.F));
        idx.erase(sl);
        idx.erase(sr);
        idx.insert(Node(al.F, al.S, al.T + ar.T));
      }
    }
    idx.erase(idx.find(Node(l, 0, 0)));
  }
  printf("%d\n", ans);
  return 0;
}