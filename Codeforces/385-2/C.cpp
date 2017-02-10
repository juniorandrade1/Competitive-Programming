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

const int N = 1111;

int n, m, k;
int vis[N][N];
int pset[N], mask[N], sz[N];

int fnd(int i) {
  return ((pset[i] == i) ? i : (pset[i] = fnd(pset[i])));
}

void uni(int a, int b) {
  int i = fnd(a), j = fnd(b);
  if(mask[i]) {
    pset[i] = j;
    mask[j] = mask[i];
    sz[j] += sz[i];
  }
  else {
    swap(i, j);
    pset[i] = j;
    mask[j] = mask[i];
    sz[j] += sz[i];
  }
}

int getSz(int i) {
  return sz[fnd(i)];
}

int getMask(int i) {
  return mask[fnd(i)];
}



int main() {
  scanf("%d %d %d", &n, &m, &k);

  for(int i = 0; i < n; ++i) {
    pset[i] = i;
    mask[i] = 0;
    sz[i] = 1;
  }

  for(int i = 0; i < k; ++i) {
    int x; scanf("%d", &x);
    mask[x - 1] = x;
  }
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    vis[a][b] = vis[b][a] = 1;
    uni(a, b);
  }

  int bstSz = -1;
  int id = -1;

  for(int i = 0; i < n; ++i) {
    if(getSz(i) > bstSz) {
      bstSz = getSz(i);
      id = i;
    }
  }
  debug("%d %d\n", bstSz, id);
  ll sol = 0;
  for(int i = 0; i < n; ++i) {
    if(getMask(i) == 0) uni(id, i);
  }

  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(getMask(i) != getMask(j)) continue;
      if(vis[i][j] == 0) {
        sol++;
        vis[i][j] = vis[j][i] = 1;
      }
    }
  }
  printf("%lld\n", sol);
  return 0;
}