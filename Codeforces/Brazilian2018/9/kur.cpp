#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 500010;

int n, m;
int p[N];
vi g[N];

inline int getqtd(int l, int r, int i) {
  return upper_bound(g[i].begin(), g[i].end(), r) - lower_bound(g[i].begin(), g[i].end(), l);
}

inline int solve(int l, int r) {
  if(l == r) return p[l];
  int len = (r - l + 1);
  int bst = -1;
  int idx = 0;
  for(int i = 0; i < 25; ++i) {
    int t = (rand() % (len - 1));
    int x = p[l + t];
    int q = getqtd(l, r, x);
    if(q > bst) {
      bst = q;
      idx = x;
    }
  }
  if(bst * 2 > len) return idx;
  else return 0;
}

int main() {
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    g[p[i]].pb(i);
  }
  while(m--) {
    int l, r; scanf("%d %d", &l, &r);
    printf("%d\n", solve(l - 1, r - 1));
  }
  return 0;
} 