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

const int N = 10010;

int l, n;
ii p[N];
vector< ii > ev;

inline void main2() {
  ev.clear();
  for(int i = 0; i < n; ++i) {
    int x, r; scanf("%d %d", &x, &r);
    int left = max(0, x - r);
    int right = min(l, x + r);
    p[i] = ii(left, right);
    ev.pb(mp(left, i));
  }
  sort(ev.begin(), ev.end());

  int qtd = 0;
  int at = 0;
  int i = 0;
  while(at < l) {
    ll bst = -1;
    for(; i < ev.size(); ++i) {
      if(ev[i].F > at) break;
      bst = max(p[ev[i].S].S, bst); 
    }
    if(bst == -1) {
      puts("-1");
      return;
    }
    qtd++;
    at = bst;
  }
  printf("%d\n", n - qtd);
}

int main() {
  while(scanf("%d %d", &l, &n) != EOF) {
    if(!l && !n) break;
    main2();
  }
  return 0;
}