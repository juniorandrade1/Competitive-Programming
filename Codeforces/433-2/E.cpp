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

const int N = 200010;

template <class T>
class Treap {
  private:
  struct node {
    T key;
    int prior;
    int size;
    node *l, *r;
    node(){};
    node(T key, int prior) : key(key), prior(prior), size(1), l(NULL), r(NULL) {}
    node(T key) : key(key), prior(rand()), size(1), l(NULL), r(NULL) {}
  };
  typedef node* pnode;

  int getSize(pnode p) { return p ? p->size : 0; }
  void updateNode(pnode p) { 
    if(p) {
      p->size = getSize(p->l) + getSize(p->r) + 1; 
    }
  }
  void split (pnode t, T key, pnode &l, pnode &r) {
    if (!t) l = r = NULL;
    else if (key < t->key) split (t->l, key, l, t->l),  r = t;
    else split (t->r, key, t->r, r),  l = t;
    updateNode(t);
  }
  void merge(pnode &t, pnode l, pnode r) {
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    updateNode(t);
  }
  void insert(pnode it, pnode &t) {
    if(!t) t = it;
    else if(it->prior > t->prior) split(t, it->key, it->l, it->r), t = it;
    else insert(it, it->key < t->key ? t->l : t->r);
    updateNode(t);
  }
  void erase(T key, pnode &t) {
    if(!t) return;
    if(t->key == key) merge(t, t->l, t->r);
    else erase(key, key < t->key ? t->l : t->r);
    updateNode(t);
  }
  void preOrder(pnode t) {
    if(!t) return;
    preOrder(t->l);
    cout << t->key << endl;
    preOrder(t->r);
  }
  int lessOrEqualThanK(T key, pnode t) {
    if(!t) return 0;
    if(t->key <= key) return getSize(t->l) + 1 + lessOrEqualThanK(key, t->r);
    else return lessOrEqualThanK(key, t->l);
  }
  public:
  pnode root;
  Treap(){
    root = NULL; 
    srand(time(NULL));
  };
  void insert(T key) { insert(new node(key), root); }
  void erase(T key) { erase(key, root); }
  void preOrder() { preOrder(root); }
  int lessOrEqualThanK(T key) { return lessOrEqualThanK(key, root); }
  int getQtdInRange(T left, T right) { return lessOrEqualThanK(right, root) - lessOrEqualThanK(left - 1, root); }
  int getSizeTree() { return getSize(root); }
};

Treap< int > tr[4 * N];

int query(int no, int l, int r, int i, int j, int rx, int ry) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no].getQtdInRange(rx, ry);
  int mid = (l + r) >> 1;
  int nxt = (no << 1);
  return query(nxt, l, mid, i, j, rx, ry) + query(nxt + 1, mid + 1, r, i, j, rx, ry);
}

void update(int no, int l, int r, int x, int y, int op) {
  if(op == 1) tr[no].insert(y);
  else tr[no].erase(y);
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(x <= mid) update(nxt, l, mid, x, y, op);
  else update(nxt + 1, mid + 1, r, x, y, op);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    update(1, 1, n, i, x, 1);
  }
  while(q--) {
    int l, r, d, u;
    scanf("%d %d %d %d", &l, &d, &r, &u);
    ll qtd = query(1, 1, n, l, r, d, u);
    ll sol = (qtd * (qtd + 1LL)) / 2LL;
    printf("%lld\n", sol);
  }
  return 0;
}