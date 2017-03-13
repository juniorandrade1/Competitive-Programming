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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif


int n, m;
vii s, t;

vii compressArray(vii at) {
  set<int>a, b;
  for(int i = 0; i < at.size(); ++i) {
    a.insert(at[i].F);
    b.insert(at[i].S);
  }
  map<int, int> idxA, idxB;
  int ca = 0, cb = 0;
  for(set<int>::iterator it = a.begin(); it != a.end(); it++) idxA[*it] = ca++;
  for(set<int>::iterator it = b.begin(); it != b.end(); it++) idxB[*it] = cb++;
  for(int i = 0; i < at.size(); ++i) {
    at[i].F = idxA[at[i].F];
    at[i].S = idxB[at[i].S];
  }
  return at;
}

inline void test() {
  vii v1 = compressArray(s);
  vii v2 = compressArray(t);
  for(int i = 0; i < n; ++i) {
    if(v1[0] == v2[i]) {
      bool ok = false;
      for(int j = 0; j < n; ++j) {
        int k = (i + j) % n;
        if(v1[j] != v2[k]) ok = true;
      }
      if(!ok) {
        puts("yes");
        exit(0);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    s.pb(mp(x, y));
  }
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    t.pb(mp(x, y));
  }
  if(n != m) {
    puts("no");
    return 0;
  }

  for(int i = 0; i < 4; ++i) {
    test();
    for(int j = 0; j < t.size(); ++j) {
      swap(t[j].F, t[j].S);
      t[j].F *= -1;
    }
  }

  puts("no");
  return 0;
}