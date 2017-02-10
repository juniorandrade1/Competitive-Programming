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

const int N = 4040;


void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int n, k;
map< int, vi > sol;

struct est {
  vi v;
  ll sum;
  est(){};
  est(vi _v) {
    v = _v;
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); ++i) sum += v[i];
  }
  bool operator < (est other) const {
    if(v.size() != other.v.size()) return v.size() < other.v.size();
    else return sum < other.sum;
  }
};

vector< est > foo;

int main() {
  arquivo();
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    sol[a].pb(b);
  }
  for(map< int, vi > :: iterator it = sol.begin(); it != sol.end(); it++) {
    foo.pb(est(it->S));
  }
  sort(foo.rbegin(), foo.rend());

  if(foo.size() < k) {
    puts("0 0");
  }
  else {
    multiset< ll > at;
    ll qtd = foo[k - 1].v.size();
    printf("%lld ", qtd);
    for(int i = 0; i < foo.size(); ++i) {
      if(foo[i].v.size() < qtd) continue;
      ll sum = 0;
      for(int j = 0; j < qtd; ++j) sum += foo[i].v[j];
      at.insert(sum);
      while(at.size() > k) at.erase(at.begin());
    }
    ll sum = 0;
    while(at.size()) sum += (*at.begin()), at.erase(at.begin());
    printf("%lld\n", sum);
  }
  
  return 0;
}