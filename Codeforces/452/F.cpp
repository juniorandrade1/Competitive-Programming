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

const int N = 200020;
const int M = 256;

int tr[4 * N];

void update(int no, int l, int r, int i, int v) {
  tr[no] += v;
  if(l == r) return;
  int nxt = (no << 1), md = (l + r) >> 1;
  if(i <= md) update(nxt, l, md, i, v);
  else update(nxt + 1, md + 1, r, i, v);
}

int query(int no, int l, int r, int x) {
  if(l == r) return l;
  int nxt = (no << 1), md = (l + r) >> 1;
  if(tr[nxt] < x) return query(nxt + 1, md + 1, r, x - tr[nxt]);
  else query(nxt, l, md, x);
}

int queryPos(int no, int l, int r, int i) {
  if(l == r) return tr[no];
  int nxt = (no << 1), md = (l + r) >> 1;
  if(i <= md) return queryPos(nxt, l, md, i);
  else return queryPos(nxt + 1, md + 1, r, i);
}

set< int > idx[M];
int n, m;
char s[N];

inline void eraseSegment(int l, int r, char c) {
  int nl = query(1, 1, n, l);
  int nr = query(1, 1, n, r);
  set< int > :: iterator itL = idx[c].lower_bound(nl);
  set< int > :: iterator itR = idx[c].upper_bound(nr);
  vector < int > needErase;
  for(set< int > :: iterator it = itL; it != itR; it++) {
    update(1, 1, n, *it, -1);
    needErase.pb(*it);
  }
  for(int i = 0; i < needErase.size(); ++i) idx[c].erase(idx[c].find(needErase[i]));
}

int main() {
  scanf("%d %d", &n, &m);
  scanf(" %s", s + 1);
  for(int i = 1; i <= n; ++i) {
    idx[s[i]].insert(i);
    update(1, 1, n, i, 1);
  }
  for(int i = 0; i < m; ++i) {
    int l, r;
    char c; 
    scanf("%d %d %c", &l, &r, &c);
    eraseSegment(l, r, c);
  }
  for(int i = 1; i <= n; ++i) if(queryPos(1, 1, n, i) == 1) printf("%c", s[i]);
  printf("\n");
  return 0;
}