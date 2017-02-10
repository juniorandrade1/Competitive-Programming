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

const ll md = (ll)1e9 + 7LL;

const int N = 1000010;

const ll addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

const ll mulMod(ll a, ll b) {
  return ((a % md) * (b % md)) % md;
}


ll fat[N];
int n, m;



vii all[N];

set<int>g;
int qtd[N];

int main() {
  fat[0] = 1;
  for(int i = 1; i < N; ++i) {
    fat[i] = mulMod(i, fat[i - 1]);
  }
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    int q; scanf("%d", &q);

    g.clear();
    for(int j = 0; j < q; ++j) {
      int x; scanf("%d", &x); x--;
      g.insert(x);
      qtd[x]++;
    }
    for(set<int>::iterator it = g.begin(); it != g.end(); it++) {
      all[*it].pb(mp(qtd[*it], i));    
    }
    for(set<int>::iterator it = g.begin(); it != g.end(); it++) qtd[*it] = 0;
  }
  
  for(int i = 0; i < N; ++i) sort(all[i].begin(), all[i].end());
  sort(all, all + m);
  
  ll ans = 1;
  for(int i = 0; i < m; ++i) {
    int j = i;
    while(j < m && all[i] == all[j]) j++;
    ans = mulMod(ans, fat[j - i]);
    i = j - 1;
  }
  printf("%lld\n", ans);

  return 0;
}