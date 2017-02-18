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

void arquivo() {
  freopen("helpcross.in", "r", stdin);
  freopen("helpcross.out", "w", stdout);
}

const int N = 20010;

int n, m;
multiset<int>s;
ii arr[N];

int main() {
  arquivo();
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    s.insert(x);
  }
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    arr[i] = mp(y, x);
  }
  sort(arr, arr + m);
  int ans = 0;
  for(int i = 0; i < m; ++i) {
    int l, r;
    l = arr[i].S;
    r = arr[i].F;
    multiset<int>::iterator it = s.lower_bound(l);
    if(it == s.end()) continue;
    if(*it >= l && *it <= r) {
      ans++;
      s.erase(it);
    }
  }
  printf("%d\n", ans);
  return 0;
}