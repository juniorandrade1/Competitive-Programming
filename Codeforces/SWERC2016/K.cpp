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

const int N = 1e5 + 10;

struct UnionFind {
  int pset[N];
  UnionFind(){ for(int i = 0; i < N; ++i) pset[i] = i; };
  int fnd(int i) { return pset[i] == i ? i : (pset[i] = fnd(pset[i])); }
  void uni(int i, int j) { pset[fnd(i)] = fnd(pset[j]); }
  bool same(int i, int j) { return fnd(i) == fnd(j); }
};

map< pair<ii, int>, int > idx3;
map< ii, int > idx2;
int c3 = 0, c2 = 0;
UnionFind u2, u3;

inline int getIdx(int x, int y, int z) {
  pair<ii, int> lol = mp(ii(x, y), z);
  if(idx3.find(lol) == idx3.end()) idx3[lol] = c3++;
  return idx3[lol];
}

inline int getIdx(int x, int y) {
  ii lol = ii(x, y);
  if(idx2.find(lol) == idx2.end()) idx2[lol] = c2++;
  return idx2[lol];
}

int main() {
  int m; scanf("%d", &m);

  bool ok1, ok2;
  ok1 = ok2 = false;

  for(int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int index13 = getIdx(x, y, z);
    int index12 = getIdx(y, z);

    scanf("%d %d %d", &x, &y, &z);
    int index23 = getIdx(x, y, z);
    int index22 = getIdx(y, z);

    ok2 |= u2.same(index12, index22);
    ok1 |= u3.same(index13, index23);

    u2.uni(index12, index22);
    u3.uni(index13, index23);

  }

  if(ok1) puts("True closed chains");
  else puts("No true closed chains");

  if(ok2) puts("Floor closed chains");
  else puts("No floor closed chains");


  return 0;
}