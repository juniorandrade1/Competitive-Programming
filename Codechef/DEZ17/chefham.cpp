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

int n;
int v[N], p[N];
map< int, vi > cnt;


inline void main2() {
  scanf("%d", &n);
  cnt.clear();
  for(int i = 0; i < n; ++i) {
    scanf("%d", v + i);
    cnt[v[i]].pb(i);
  }
  if(n <= 10) {
    int bst = -1;
    int arr[n];
    for(int i = 0; i < n; ++i) p[i] = i;
    do {
      int foo = 0;
      for(int i = 0; i < n; ++i) foo += (v[i] != v[p[i]]);
      if(bst < foo) {
        bst = foo;
        for(int i = 0; i < n; ++i) arr[i] = p[i];
      }
    }
    while(next_permutation(p, p + n));
    for(int i = 0; i < n; ++i) p[i] = arr[i];
  }
  else {
    vi o, t;
    for(map<int, vi> :: iterator it = cnt.begin(); it != cnt.end(); it++) {
      if(it->S.size() == 1) o.pb(it->S[0]);
      else {
        t.pb(it->S[0]);
        t.pb(it->S[1]);
      }
    }
    int szt = t.size();
    if(t.size() == 2) {
      int x0, x1;
      x0 = o.back(); o.pop_back();
      x1 = o.back(); o.pop_back();
      p[x0] = t[0];
      p[t[0]] = x0;
      p[x1] = t[1];
      p[t[1]] = x1;
    }
    else if(t.size() > 2) { 
      for(int i = 0; i < szt; ++i) {
        int nx = (i + 2) % szt;
        p[t[nx]] = t[i];
      }
    }
    int szo = o.size();
    for(int i = 0; i < szo; ++i) {
      p[o[(i + 1) % szo]] = o[i];
    }
  }
  int sol = 0;
  for(int i = 0; i < n; ++i) sol += (v[i] != v[p[i]]);
  printf("%d\n", sol);
  for(int i = 0; i < n; ++i) {
    printf("%d ", v[p[i]]);
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
