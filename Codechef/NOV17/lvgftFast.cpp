#include <bits/stdc++.h>

using namespace std;

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
  vector< T > getTree(pnode t) {
    if(!t) return vector< T > ();
    vector< T > lft = getTree(t->l);
    lft.push_back(t->key);
    vector< T > rgt = getTree(t->r);
    if(lft.size() > rgt.size()) {
      for(int i = 0; i < rgt.size(); ++i) lft.push_back(rgt[i]);
      return lft;
    }
    else {
      for(int i = 0; i < lft.size(); ++i) rgt.push_back(lft[i]);
      return rgt;
    }
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
  void clear() { root = NULL; }
  int size() { return getSize(root); }
  vector< T > getTree() { return getTree(root); }
};




const int N = 100010;

typedef pair<int, int> ii;

int n, m;
vector< int > g[N];
int marked[N];
ii que[N];
Treap< int > activeSet[N];
int pset[N], setCounter;

inline void init() {
  setCounter = 1;
  for(int i = 1; i <= n; ++i) {
    g[i].clear();
    pset[i] = 0;
    marked[i] = 0;
    activeSet[i].clear();
  }
}

inline int fnd(int i) { return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }

inline void regroup(int x) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    int fx = fnd(x), fy = fnd(y);
    if(activeSet[fx].size() < activeSet[fy].size()) swap(fx, fy);
    vector< int > getNodes = activeSet[fy].getTree();
    for(int i = 0; i < getNodes.size(); ++i) activeSet[fx].insert(getNodes[i]);
    //for(set<int>::iterator it = activeSet[fy].begin(); it != activeSet[fy].end(); it++) activeSet[fx].insert(*it);
    activeSet[fy].clear();
    pset[fy] = fx;
  }
}

inline int getSecondBest(int x) {
  if(marked[x] > 0) return n - 1;
  int fx = fnd(x);
  if(activeSet[fx].size() >= n - 1) return -1;
  int lo = 1, hi = n;
  while(lo < hi) {
    int md = (lo + hi + 1) >> 1;
    if(activeSet[fx].getQtdInRange(md, n) + 2 <= (n - md + 1)) lo = md;
    else hi = md - 1;
  }
  return lo;
}

void dfs(int x, int ult) {
  if(marked[x]) return;
  if(pset[x]) return;
  pset[x] = setCounter;
  activeSet[pset[x]].insert(x);
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(y == ult) continue;
    dfs(y, x);
  }
}

int sol[N];

inline void main2() {
  scanf("%d %d", &n, &m);
  init();
  for(int i = 0; i + 1 < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 0; i < m; ++i) {
    int type, x;
    scanf("%d %d", &type, &x);
    que[i] = make_pair(type, x);
    if(type == 1) marked[x]++;
  }

  for(int i = 1; i <= n; ++i) {
    if(marked[i] > 0) {
      pset[i] = setCounter++;
      activeSet[pset[i]].insert(i);
      continue;
    }
    if(pset[i] == 0) {
      dfs(i, i);
      setCounter++;
    } 
  }

  for(int i = m - 1; i >= 0; --i) {
    int type = que[i].first, x = que[i].second;
    if(type == 1) {
      marked[x]--;
      if(!marked[x]) regroup(x);
    }
    else {
      sol[i] = getSecondBest(x);
    }
  }

  for(int i = 0; i < m; ++i) {
    int type = que[i].first, x = que[i].second;
    if(type == 2) printf("%d\n", sol[i]);
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}