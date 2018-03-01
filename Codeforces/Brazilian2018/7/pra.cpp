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

struct Segment {
  int l, r, id;
  Segment(){};
  Segment(int _l, int _r, int _id) {
    l = _l;
    r = _r;
    id = _id;
  }
  void read(int _id) {
    scanf("%d %d", &l, &r);
    id = _id;
  }
  bool operator < (Segment o) const {
    if(l != o.l) return l < o.l;
    return r < o.r;
  }
};

const int N = 2000020;

int bit[N];
void update(int x, int v) {
  x += 2;
  while(x < N) {
    bit[x] += v;
    x += LSONE(x);
  }
}
int query(int x) {
  x += 2;
  int ret = 0;
  while(x) {
    ret += bit[x];
    x -= LSONE(x);
  }
  return ret;
}

int n, k;
Segment s[N];
vector< int > cx;

int getIdx(int x) {
  return lower_bound(cx.begin(), cx.end(), x) - cx.begin();
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    s[i].read(i + 1);
    cx.pb(s[i].l);
    cx.pb(s[i].r);
  }
  sort(s, s + n);
  sort(cx.begin(), cx.end());
  cx.erase(unique(cx.begin(), cx.end()), cx.end());
  int ans = 0;
  int al, ar;
  for(int i = 0; i < n; ++i) {
    int gl = getIdx(s[i].l);
    int gr = getIdx(s[i].r);
    update(gl, 1);
    update(gr + 1, -1);
    int lo = gl, hi = gr;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(query(lo) <= k) hi = md;
      else lo = md + 1;
    }
    if(query(lo) < k) continue;
    int vl = cx[gl];
    int vr = cx[lo];
    if(ans < vr - vl) {
      ans = vr - vl;
      al = vl;
      ar = vr;
    }
    ans = max(ans, vr - vl);
  }
  printf("%d\n", ans);
  vector< int > sol;
  for(int i = 0; i < n && sol.size() < k; ++i) {
    if(s[i].l <= al && s[i].r >= ar) sol.pb(s[i].id);
  }
  sort(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i) {
    if(i) printf(" ");
    printf("%d", sol[i]);
  }
  return 0;
} 