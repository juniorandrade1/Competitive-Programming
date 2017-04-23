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

const int N = 1000001;

set< int > s;

inline void main2(int _test) {
  printf("Case #%d: ", _test);
  ll n, k; scanf("%lld %lld", &n, &k);
  s.clear();
  s.insert(-n);
  k--;
  for(int i = 0; i < k; ++i) {
    int foo = -(*s.begin());
    s.erase(s.begin());
    if(foo > 1) {
      int a = foo / 2;
      int b = foo - a;
      b--;
      if(a >= 0) s.insert(-a);
      if(b >= 0) s.insert(-b);
    }
  }
  set<int>::iterator it1, it2;
  it1 = s.begin();
  it2 = s.begin();
  if(s.size() == 0) puts("0 0");
  else if(s.size() == 1) {
    printf("%d %d\n", -(*it1), -(*it2));
  }
  else {
    it2++;
    printf("%d %d\n", -(*it1), -(*it2));
  }
    s.clear();
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}