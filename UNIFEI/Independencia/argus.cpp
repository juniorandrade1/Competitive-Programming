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

const int N = 123455;
struct est {
  ll id, period, atTime, differSomething;
  est(){};
  est(ll _id, ll _period, ll _atTime) {
    id = _id;
    period = _period;
    atTime = _atTime;
    differSomething = rand();
  }
  bool operator < (est other) const {
    if(atTime != other.atTime) return atTime < other.atTime;
    if(id != other.id) return id < other.id;
    return differSomething < other.differSomething;
  }
  void read() {
    scanf("%lld %lld", &id, &period);
    atTime = period;
    differSomething = rand();
  }
};

char s[N];
map<int, int> qtdCall;
multiset< est > all;

int main() {
  srand(time(NULL));
  while(1) {
    scanf(" %s", s);
    if(strcmp(s, "Register")) break;
    est foo; foo.read();
    all.insert(foo);
    qtdCall[foo.id] = 0;
  }
  int k; scanf("%d", &k);
  while(k--) {
    est at = *all.begin(); all.erase(all.begin());
    qtdCall[at.id]++;
    at.atTime += at.period;
    all.insert(at);
  }

  for(map<int, int>::iterator it = qtdCall.begin(); it != qtdCall.end(); it++) {
    printf("Register %d = %d\n", it->F, it->S);
  }
  return 0;
}