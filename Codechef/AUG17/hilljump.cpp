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

const int N = 100001;
const int SQ = 200;

ll v[N], plusBlock[N];
int n, q;
int nxt[N], f[N], fSize[N];

inline ll getValue(int pos) {
  return v[pos] + plusBlock[pos / SQ];
}

inline void findNxt(int l, int r) {
  l = max(l, 0);
  r = min(r, n - 1);
  stack< ii > s;
  for(int i = min(n - 1, r + 100); i > r; --i) {
    while(!s.empty() && s.top().F <= getValue(i)) s.pop();
    s.push(mp(getValue(i), i));
  }
  for(int i = r; i >= l; --i) {
    while(!s.empty() && (s.top().F <= getValue(i) || s.top().S - i > 100)) s.pop();
    if(s.empty()) nxt[i] = i;
    else nxt[i] = s.top().S;
    s.push(mp(getValue(i), i));
  }
}

inline void findF(int l, int r) {
  l = max(l, 0);
  r = min(r, n - 1);
  deque< ii > s;
  for(int i = min(n - 1, r + 100); i > r; --i) {
    while(!s.empty() && s.back().F <= getValue(i)) s.pop_back();
    s.push_back(mp(getValue(i), i));
  }
  for(int i = r; i >= l; --i) {
    while(!s.empty() && (s.back().F <= getValue(i) || s.back().S - i > 100)) s.pop_back();
    while(!s.empty() && (s.front().S / SQ != (i / SQ))) s.pop_front();
    if(s.empty()) {
      f[i] = i;
      fSize[i] = 0;
    }
    else {
      f[i] = s.front().S;
      fSize[i] = s.size();
    }
    s.push_back(mp(getValue(i), i));
  }
}

inline int query(int p, int x) {
  while(x) {
    if(p == nxt[p]) return p;
    if(x > fSize[p]) {
      x -= fSize[p];
      p = f[p];
    }
    p = nxt[p];
    x--;
  }
  return p;
}

inline void update(int l, int r, ll x) {
  int bl = l / SQ;
  int br = r / SQ;
  if(bl == br) {
    for(int i = l; i <= r; ++i) v[i] += x;
    findNxt(r - 200, r);
    findNxt(l - 200, l);
    findF(r - 200, r);
    findF(l - 200, l);
  }
  else {
    for(int i = l; i < min((bl + 1) * SQ, n); ++i) v[i] += x;
    for(int i = br * SQ; i <= r; ++i) v[i] += x;
    for(int i = bl + 1; i <= br - 1; ++i) plusBlock[i] += x;
    findNxt(r - 200, r);
    findNxt(l - 200, l);
    findF(r - 200, r);
    findF(l - 200, l);
  }
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  findNxt(0, n - 1);
  findF(0, n - 1);
  while(q--) {
    int op; scanf("%d", &op);
    if(op == 1) {
      int p, x; scanf("%d %d", &p, &x); p--;
      printf("%d\n", query(p, x) + 1);
    }
    else {
      int l, r, x; scanf("%d %d %d", &l, &r, &x);
      l--; r--;
      update(l, r, x);
    }
  }
  return 0;
}
