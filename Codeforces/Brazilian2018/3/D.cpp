
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
  int getK(int x, pnode t) {
    if(getSize(t) < x) assert(false);
    if(getSize(t->l) < x) {
      x -= getSize(t->l);
      x--; if(x == 0) return t->key.S;
      return getK(x, t->r);
    }
    else return getK(x, t->l);
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
  int getK(int x) { return getK(x, root); }
};

Treap< ii > tr;

const int N = 200101;

int idInc = 0;
int n;
char s[N];
char cd[N];
map< string, ii > issue;
map< int, string > idx;


inline void tryFind(int x) {
  if(issue.size() == 0) {
    puts("EMPTY");
    return;
  }
  if(x >= issue.size()) x = issue.size() - 1;
  int s = tr.getK(x + 1);
  string sol = idx[s];
  printf("OK %s %lld %lld\n", sol.c_str(), issue[sol].F, issue[sol].S);
}

int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    if(strcmp(s, "ISSUE") == 0) {
      scanf(" %s", cd);
      if(issue.find((string)cd) == issue.end()) {
        idx[idInc] = (string)cd;
        issue[(string)cd] = ii(idInc++, 0);
        printf("CREATED %lld %lld\n", issue[(string)cd].F, issue[(string)cd].S);
        tr.insert(ii(-issue[(string)cd].S, issue[(string)cd].F));
      } 
      else {
        printf("EXISTS %lld %lld\n", issue[(string)cd].F, issue[(string)cd].S);
      }
    }
    else if(strcmp(s, "DELETE") == 0) {
      scanf(" %s", cd);
      if(issue.find((string)cd) == issue.end()) {
        printf("BAD REQUEST\n");
      } 
      else {
        printf("OK %lld %lld\n", issue[(string)cd].F, issue[(string)cd].S);
        tr.erase(ii(-issue[(string)cd].S, issue[(string)cd].F));
        issue.erase(issue.find((string)cd));
      }
    }
    else if(strcmp(s, "RELIABILITY") == 0) {
      scanf(" %s", cd);
      ll v; scanf("%lld", &v);
      if(issue.find((string)cd) != issue.end()) {
        string ax = (string)cd;
        tr.erase(ii(-issue[(string)cd].S, issue[(string)cd].F));
        issue[ax].S += v;
        tr.insert(ii(-issue[(string)cd].S, issue[(string)cd].F));
        printf("OK %lld %lld\n", issue[ax].F, issue[ax].S);
      }
      else {
        printf("BAD REQUEST\n");
      }
    }
    else {
      int x; scanf("%d", &x);
      tryFind(x);
    }
  }
  return 0;
}