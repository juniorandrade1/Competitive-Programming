#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ull, ull > ii;
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

const int N = 1e4;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

const ull md = 1e9 + 7LL;

ull B = 37;

ull B2 = 33;

ull mulMod(ull a, ull b) {
  return ((a % md) * (b % md)) % md;
}

ull addMod(ll a, ll b) {
  return ((a % md) + (b % md)) % md;
}

ull subMod(ll a, ll b) {
  a %= md;
  b %= md;
  a += md;
  b += md;
  return ((a - b + md) % md);
}

int n, l, m;
char s[1010][101];
ull pot[101], pot2[101];
ull hs[101], hs2[101];
int ans[1010];

map< ii, set<int> > optimal;
map< ii, set<int> > :: iterator optIt;
set< int > :: iterator sIt;

inline void go(int p1, int w1, int p2, int w2) {
  optimal[ii(hs[p1], hs2[p1])].erase(optimal[ii(hs[p1], hs2[p1])].find(p1));
  if(p1 != p2) optimal[ii(hs[p2], hs2[p2])].erase(optimal[ii(hs[p2], hs2[p2])].find(p2));

  hs[p1] -= pot[w1] * (s[p1][w1] - 'a' + 1);
  hs[p2] -= pot[w2] * (s[p2][w2] - 'a' + 1);

  hs2[p1] = subMod(hs2[p1], mulMod(pot2[w1], (s[p1][w1] - 'a' + 1)));
  hs2[p2] = subMod(hs2[p2], mulMod(pot2[w2], (s[p2][w2] - 'a' + 1)));

  swap(s[p1][w1], s[p2][w2]);
  hs[p1] += pot[w1] * (s[p1][w1] - 'a' + 1);
  hs[p2] += pot[w2] * (s[p2][w2] - 'a' + 1);

  hs2[p1] = addMod(hs2[p1], mulMod(pot2[w1], (s[p1][w1] - 'a' + 1)));
  hs2[p2] = addMod(hs2[p2], mulMod(pot2[w2], (s[p2][w2] - 'a' + 1)));
  
  optimal[ii(hs[p1], hs2[p1])].insert(p1);
  int sol1 = optimal[ii(hs[p1], hs2[p1])].size();
  for(sIt = optimal[ii(hs[p1], hs2[p1])].begin(); sIt != optimal[ii(hs[p1], hs2[p1])].end(); sIt++) ans[*sIt] = max(ans[*sIt], sol1);
  if(p1 != p2) {
    optimal[ii(hs[p2], hs2[p2])].insert(p2);
    int sol2 = optimal[ii(hs[p2], hs2[p2])].size();
    for(sIt = optimal[ii(hs[p2], hs2[p2])].begin(); sIt != optimal[ii(hs[p2], hs2[p2])].end(); sIt++) ans[*sIt] = max(ans[*sIt], sol2);
  } 
}

int main() {
  scanf("%d %d %d", &n, &l, &m);
  for(int i = 0; i < n; ++i) scanf(" %s", s[i]);
  pot[0] = 1LL;
  pot2[0] = 1LL;
  for(int i = 1; i < 101; ++i) {
    pot[i] = pot[i - 1] * B;
    pot2[i] = mulMod(pot2[i - 1], B2);
  }
  for(int i = 0; i < n; ++i) {
    hs[i] = 0;
    hs2[i] = 0;
    for(int j = 0; j < l; ++j) {
      hs[i] += ((s[i][j] - 'a' + 1) * pot[j]);
      hs2[i] = addMod(hs2[i], mulMod((s[i][j] - 'a' + 1), pot2[j]));
    }
    optimal[ii(hs[i], hs2[i])].insert(i);
  }
  for(optIt = optimal.begin(); optIt != optimal.end(); optIt++) {
    int sol = optIt->S.size();
    for(sIt = optIt->S.begin(); sIt != optIt->S.end(); sIt++) ans[*sIt] = sol;
  }
  while(m--) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    go(a, b, c, d);
  }
  for(int i = 0; i < n; ++i) printf("%d\n", ans[i]);
  return 0;
}