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


typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;
    item(){};
    item(int x) {
      value = x;
      prior = rand();
      cnt = 0;
      rev = false;
      l = NULL;
      r = NULL;
    }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem &t, int l, int r) {
  pitem t1, t2, t3;
  split (t, t1, t2, l);
  split (t2, t2, t3, r-l+1);
  t2->rev ^= true;
  merge (t, t1, t2);
  merge (t, t, t3);
}

void cyclicShift(pitem &t, int l, int r) {
  int sz = r - l + 1;
  if(sz == 1) return;
  pitem t1, t2, t3, t4;
  split (t, t1, t2, l);
  split (t2, t2, t3, sz);
  split(t2, t2, t4, sz - 1);
  merge(t2, t4, t2);
  merge (t, t1, t2);
  merge (t, t, t3);
}

int arr[2223456];
int sz = 1;

void output (pitem t) {
  if (!t)  return;
  push (t);
  output (t->l);
  arr[sz++] = t->value;
  output (t->r);
}


int n, q, m;
pitem root;

int main() {
  srand(time(NULL));
  scanf("%d %d %d", &n, &q, &m);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    merge(root, root, new item(x));
  }
  while(q--) {
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    if(op == 1) cyclicShift(root, l - 1, r - 1);
    else reverse(root, l - 1, r - 1);
  }
  output(root);
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x);
    printf("%d ", arr[x]);
  }
  return 0;
}