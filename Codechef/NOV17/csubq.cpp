#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500001;
 
typedef long long ll;
 
int n, q, l, r; 
 
struct Node {
  ll qtd;
  int mxDir, mxEsq, mnEsq, mnDir;
  int left, right;
  Node(){
    mxDir = mxEsq = mnDir = mnEsq = qtd = left = right = -1;
  };
  Node(int val, int idx) {
    mxDir = mxEsq = mnDir = mnEsq = left = right = -1;
    qtd = 0;
    left = right = idx;
    if(val > r) {
      mxEsq = mxDir = idx;
    }
    else if(val >= l) {
      mnEsq = mnDir = idx;
      qtd = 1;
    }
  }
  Node(ll _qtd, int _mxDir, int _mxEsq, int _mnEsq, int _mnDir, int _left, int _right) {
    qtd = _qtd;
    mxDir = _mxDir;
    mxEsq = _mxEsq;
    mnDir = _mnDir;
    mnEsq = _mnEsq;
    left = _left;
    right = _right;
  }
  void printNode() {
    printf("qtd = %lld\n", qtd);
    printf("mxEsq = %d\n", mxEsq);
    printf("mxDir = %d\n", mxDir);
    printf("mnEsq = %d\n", mnEsq);
    printf("mnDir = %d\n", mnDir);
    printf("left = %d\n", left);
    printf("right = %d\n", right);
  }
};
 
Node tr[4 * N];
 
 
Node join(Node a, Node b) {
  if(a.qtd == -1) return b;
  if(b.qtd == -1) return a;
 
  ll mxL, mnL, mxR, mnR;
  mxL = (a.mxDir != -1) ? a.mxDir : (a.left - 1);
  mnL = (a.mnDir != -1) ? a.mnDir : -1;
  mxR = (b.mxEsq != -1) ? b.mxEsq : (b.right + 1);
  mnR = (b.mnEsq != -1) ? b.mnEsq : -1;
 
  ll foo = 0;
 
  if(mnL != -1 && mnR != -1) {
    if(mxL < mnL && mxR > mnR) {
      foo = ((mnL - mxL) * (mxR - b.left)) + ((a.right - mxL) * (mxR - mnR)) - ((mxR - mnR) * (mnL - mxL));
    }
    else if(mxL < mnL && mxR < mnR) {
      foo = (mnL - mxL) * (mxR - b.left);
    }
    else if(mxL > mnL && mxR > mnR) {
      foo = (a.right - mxL) * (mxR - mnR);
    }
  }
  else if(mnR != -1) {
    if(mxR >= mnR) foo = (mxR - mnR) * (a.right - mxL);
  }
  else if(mnL != -1) {
    if(mnL >= mxL) foo = (mnL - mxL) * (mxR - b.left);
  }
 
  int nmxDir, nmxEsq, nmnEsq, nmnDir;
  nmxDir = nmxEsq = nmnEsq = nmnDir = -1;
 
  if(b.mxDir != -1) nmxDir = b.mxDir;
  else if(a.mxDir != -1) nmxDir = a.mxDir;
 
  if(b.mnDir != -1) nmnDir = b.mnDir;
  else if(a.mnDir != -1) nmnDir = a.mnDir;
 
 
  if(a.mxEsq != -1) nmxEsq = a.mxEsq;
  else if(b.mxEsq != -1) nmxEsq = b.mxEsq;
 
  if(a.mnEsq != -1) nmnEsq = a.mnEsq;
  else if(b.mnEsq != -1) nmnEsq = b.mnEsq;
 
  Node sol;
  sol.mxEsq = nmxEsq;
  sol.mxDir = nmxDir;
  sol.mnEsq = nmnEsq;
  sol.mnDir = nmnDir;
  sol.qtd = a.qtd + b.qtd + foo;
  sol.left = a.left;
  sol.right = b.right;
 
  if(!(sol.mxEsq == -1 || (sol.mxEsq >= sol.left && sol.mxEsq <= sol.right))) {
    printf("RUIM\n");
    printf("NODE A\n");
    a.printNode();
    printf("\n\nNODE B\n");
    b.printNode();
    printf("\n\n MERGED\n");
    sol.printNode();
  }
 
  assert(sol.mxEsq == -1 || (sol.mxEsq >= sol.left && sol.mxEsq <= sol.right));
  assert(sol.mxDir == -1 || (sol.mxDir >= sol.left && sol.mxDir <= sol.right));
  assert(sol.mnEsq == -1 || (sol.mnEsq >= sol.left && sol.mnEsq <= sol.right));
  assert(sol.mnDir == -1 || (sol.mnDir >= sol.left && sol.mnDir <= sol.right));
 
 
  /*
  a.printNode();
  printf("\n---\n");
  b.printNode();
  printf("\n---\n");
  sol.printNode();
  printf("\n---\n");
  */
 
  return sol;
}
 
 
void build(int no, int l, int r) {
  if(l == r) {
    tr[no] = Node(0, -1, -1, -1, -1, l, l);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid); build(nxt + 1, mid + 1, r);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
}
 
void update(int no, int l, int r, int i, int foo){
  if(l == r) {
    Node bar = Node(foo, l);
    tr[no] = bar;
    assert(tr[no].left == l && tr[no].right == r);
    if(!(tr[no].mnEsq == -1 || (tr[no].mnEsq >= tr[no].left && tr[no].mnEsq <= tr[no].right))) {
      printf("UPDATE BAD - %d\n", i - foo);
      tr[no].printNode();
    }
    assert(tr[no].mxEsq == -1 || (tr[no].mxEsq >= tr[no].left && tr[no].mxEsq <= tr[no].right));
    assert(tr[no].mxDir == -1 || (tr[no].mxDir >= tr[no].left && tr[no].mxDir <= tr[no].right));
    assert(tr[no].mnEsq == -1 || (tr[no].mnEsq >= tr[no].left && tr[no].mnEsq <= tr[no].right));
    assert(tr[no].mnDir == -1 || (tr[no].mnDir >= tr[no].left && tr[no].mnDir <= tr[no].right));
 
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, foo);
  else update(nxt + 1, mid + 1, r, i, foo);
  tr[no] = join(tr[nxt], tr[nxt + 1]);
  /*
  printf("[%d %d]\n", l, r);
  tr[no].printNode();
  printf("\n----------\n");
  //exit(0);    
  */
}
 
Node query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return Node();
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));  
}
 
 
void produceCase() {
  srand(time(NULL));
  n = rand() % 5000;
  q = rand() % 5000;
  l = rand() % 1000;
  r = rand() % 1000;
  if(l > r) swap(l, r);
  FILE *f = fopen("inGen", "w");
  fprintf(f, "%d %d %d %d\n", n, q, l, r);
  for(int i = 0; i < q; ++i) {
    int op, x, y;
    op = rand() % 2 + 1;
    if(op == 1) {
      x = rand() % n + 1;
      y = rand() % 5000;
    }
    else {
      x = rand() % n + 1;
      y = rand() % n + 1;
      if(x > y) swap(x, y);
    }
    fprintf(f, "%d %d %d\n", op, x, y);
  }
  fclose(f);
}
 
 
int main() {
  //produceCase();
  //freopen("inGen", "r", stdin);
  scanf("%d %d %d %d", &n, &q, &l, &r);
  build(1, 1, n);
  for(int i = 0; i < q; ++i) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if(op == 1) {
      update(1, 1, n, x, y);
    }
    else {
      Node ans = query(1, 1, n, x, y);  
      printf("%lld\n", ans.qtd);
    }
  }
  return 0;
} 
