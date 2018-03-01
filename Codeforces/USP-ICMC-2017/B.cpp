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

multiset<int> s;
int n, b;

int main() {
  scanf("%d %d", &n, &b);
  for(int i = 0; i < 2 * n; ++i) {
    int x; scanf("%d", &x);
    s.insert(x);
  }
  vi ans, sobra;
  while(!s.empty()) {
    int x = *(--s.end()); s.erase(s.find(x));
    multiset<int>::iterator it = s.lower_bound(b - x);
    if(s.empty() || it == s.begin()) sobra.pb(x);
    else {
      it--;
      ans.pb((x + (*it)) % b);
      s.erase(it);
    }
  }
  sort(sobra.begin(), sobra.end());
  for(int i = 0; i + 1 < sobra.size(); i += 2) ans.pb((sobra[i] + sobra[i + 1]) % b);
  sort(ans.rbegin(), ans.rend());
  for(int i = 0; i < n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}