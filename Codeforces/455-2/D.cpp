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

const int N = 1000010;



char s[N];
int n;
vector< int > v[2];
int bit[N];

void update(int x, int v) {
  x += 3;
  while(x < N) {
    bit[x] += v;
    x += LSONE(x);
  }
}

int query(int x) {
  int ret = 0;
  x += 3;
  while(x) {
    ret += bit[x];
    x -= LSONE(x);
  }
  return ret;
}

int queryRange(int l, int r) {
  return query(r) - query(l - 1);
}

int gl(int x) {
  int lo = -1, hi = x - 1;
  while(lo < hi) {
    int md = (lo + hi + 1) >> 1;
    if(queryRange(md, x - 1) == 0) hi = md - 1;
    else lo = md;
  }
  return lo;
}

int gr(int x) {
  int lo = x + 1, hi = n;
  while(lo < hi) {
    int md = (lo + hi) >> 1;
    if(queryRange(x + 1, md) == 0) lo = md + 1;
    else hi = md;
  }
  return lo;  
}

int check(int x) {
  int l = gl(x);
  int r = gr(x);
  int ok = 0;
  if(l != -1 && s[l] != s[x]) ok = 1;
  if(r != n && s[r] != s[x]) ok = 1;
  return ok;
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  for(int i = 0; i < n; ++i) update(i, 1);
  for(int i = 0; i < n; ++i) {
    if(i && i + 1 < n) {
      if(s[i] != s[i - 1] || s[i] != s[i + 1]) v[0].pb(i);
    }
    else if(i) {
      if(s[i] != s[i - 1]) v[0].pb(i);
    }
    else if(i + 1 < n) {
      if(s[i] != s[i + 1]) v[0].pb(i);
    }
  }

  for(int i = 0;; ++i) {
    if(v[i % 2].size() == 0) {
      printf("%d\n", i);
      return 0;
    }
    int op = i % 2;
    for(int j = 0; j < v[op].size(); ++j) {
      update(v[op][j], -1);
    }
    set< int > nw;
    for(int j = 0; j < v[op].size(); ++j) {
      int l = gl(v[op][j]);
      if(l != -1) nw.insert(l);
      int r = gr(v[op][j]);
      if(r != n) nw.insert(r);
    }
    for(set< int > :: iterator it = nw.begin(); it != nw.end(); ++it) {
      if(check(*it)) v[op ^ 1].pb(*it);
    }
    v[op].clear();
  }


  return 0;
}