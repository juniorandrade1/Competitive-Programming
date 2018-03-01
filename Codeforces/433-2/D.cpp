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

const int N = 123456;

struct flights {
  ll d, f, t, c;
  void read() { scanf("%lld %lld %lld %lld", &d, &f, &t, &c); }
  bool operator < (flights other) {
    if(d != other.d) return d < other.d;
    return t < other.t;
  }
};

int n, m, k;
flights all[N];

ll prefixMinScore[N];
bool goodPrefix[N];
ll suffix[N];
ll suffixMinScore[N];
bool goodSuffix[N];

ll allScores[N];
bool exists[N];


inline void processPrefix() {
  int qtd = 0;
  memset(exists, 0, sizeof exists);
  for(int i = 0; i <= n; ++i) allScores[i] = LINF;
  for(int i = 1; i <= m; ++i) {
    prefixMinScore[i] = prefixMinScore[i - 1];
    if(all[i].t == 0) {
      if(exists[all[i].f]) prefixMinScore[i] -= allScores[all[i].f];
      allScores[all[i].f] = min(allScores[all[i].f], all[i].c);
      prefixMinScore[i] += allScores[all[i].f];
      if(exists[all[i].f] == 0) qtd++;
      exists[all[i].f] = 1;
      goodPrefix[i] = (qtd == n);
    }
  }
}

inline void processSuffix() {
  int qtd = 0;
  memset(exists, 0, sizeof exists);
  for(int i = 0; i <= n; ++i) allScores[i] = LINF;
  for(int i = m; i >= 1; --i) {
    suffixMinScore[i] = suffixMinScore[i + 1];
    if(all[i].f == 0) {
      if(exists[all[i].t]) suffixMinScore[i] -= allScores[all[i].t];
      allScores[all[i].t] = min(allScores[all[i].t], all[i].c);
      suffixMinScore[i] += allScores[all[i].t];
      if(exists[all[i].t] == 0) qtd++;
      exists[all[i].t] = 1;
      goodSuffix[i] = (qtd == n);
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= m; ++i) all[i].read();
  sort(all + 1, all + m + 1);
  processPrefix();
  processSuffix();
  ll bstCost = LINF; 
  int nxt = 1;
  for(int i = 1; i <= m; ++i) {
    while(nxt <= m && all[nxt].d - all[i].d <= k) nxt++;
    if(nxt <= m && goodPrefix[i] && goodSuffix[nxt]) {
      bstCost = min(bstCost, prefixMinScore[i] + suffixMinScore[nxt]);
    }
  }
  if(bstCost == LINF) puts("-1");
  else printf("%lld\n", bstCost);
  return 0;
}