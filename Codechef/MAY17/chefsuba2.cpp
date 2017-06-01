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

const int N = 200020;

int n, k, p;
int v[N];
char s[N];
int pd[N];
int rPd[N];

int tr[4 * N];
int lz[4 * N];

void propagate(int no, int l, int r) {
  tr[no] += lz[no];
  if(l != r) {
    int nxt = (no << 1);
    lz[nxt] += lz[no];
    lz[nxt + 1] += lz[no];
  }
  lz[no] = 0;
}

int query(int no, int l, int r, int i, int j) {
  propagate(no, l, r);
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return max(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

void update(int no, int l, int r, int i, int j, int val) {
  propagate(no, l, r);
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    lz[no] += val;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  update(nxt, l, mid, i, j, val); update(nxt + 1, mid + 1, r, i, j, val);
  tr[no] = max(tr[nxt], tr[nxt + 1]);
}

int main() {
  scanf("%d %d %d", &n, &k, &p);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    v[i + n] = v[i];
  }

  for(int i = n * 2; i >= 1; --i) {
    if(v[i] == 0) rPd[i] = -1;
    else if(i == n * 2 || rPd[i + 1] == -1) rPd[i] = i;
    else rPd[i] = rPd[i + 1];
  }

  for(int i = 1; i <= 2 * n; ++i) {
    if(v[i]) pd[i] = pd[i - 1] + 1;
    else pd[i] = 0;
    update(1, 1, 2 * n, i, i, pd[i]);
  }

  int stPos = 1;
  scanf(" %s", s);
  int len = strlen(s);
  for(int i = 0; i < len; ++i) {
    if(s[i] == '?') {
      if(rPd[stPos] == -1) printf("%d\n", query(1, 1, 2 * n, stPos, stPos + n - 1));
      else {
        update(1, 1, 2 * n, stPos, rPd[stPos], -pd[stPos - 1]);
        printf("%d\n", min(k, query(1, 1, 2 * n, stPos, stPos + n - 1)));
        update(1, 1, 2 * n, stPos, rPd[stPos], pd[stPos - 1]);
      }
    }
    else stPos--;
    if(stPos == 0) stPos += n;
  }
  return 0;
}