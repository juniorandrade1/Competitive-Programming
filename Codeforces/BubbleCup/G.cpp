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

const ull B1 = 37LL;
const ull B2 = 73LL; 

#define pi acos(-1.0)

const int N = 100010;

char s[50];
int len;
int n, m;

map< pair<ull, ull> , int> idx;

map< pair<ull, ull>, bool > vis;
int sol;

inline void back(int pos, ull hs1, ull hs2) {
  if(pos == len) {
    if(vis[mp(hs1, hs2)]) return;
    vis[mp(hs1, hs2)] = 1;
    sol += idx[mp(hs1, hs2)];
    return;
  }
  if(s[pos] >= 'a' && s[pos] <= 'e') {
    int d = s[pos] - 'a' + 1;
    back(pos + 1, hs1 * B1 + (ull)d, hs2 * B2 + (ull)d);
  }
  else {
    back(pos + 1, hs1, hs2);
    for(int i = 1; i <= 5; ++i) back(pos + 1, hs1 * B1 + (ull)i, hs2 * B2 + (ull)i);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    len = strlen(s);
    ull hs1 = 0, hs2 = 0;
    for(int j = 0; j < len; ++j) {
      hs1 *= B1;
      hs1 += (s[j] - 'a' + 1);
      hs2 *= B2;
      hs2 += (s[j] - 'a' + 1);
    }
    idx[mp(hs1, hs2)]++;
  }
  for(int i = 0; i < m; ++i) {
    vis.clear();
    scanf(" %s", s);
    len = strlen(s);
    sol = 0;
    back(0, 0, 0);
    printf("%d\n", sol);
  }
  return 0;
} 