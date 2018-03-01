#include <bits/stdc++.h>

using namespace std;

const int N = 500001;

typedef long long ll;



int n, q, l, r; 
int v[N];

ll query(int _l, int _r) {
  ll sol = 0;
  for(int i = _l; i <= _r; ++i) {
    int tp = 0;
    for(int j = i; j <= _r; ++j) {
      tp = max(tp, v[j]);
      if(tp > r) break;
      sol += (tp >= l && tp <= r);
    }
  }
  return sol;
}


void produceCase() {
  srand(time(NULL));
  n = rand() % 10;
  q = rand() % 50 + 1;
  l = rand() % 10;
  r = rand() % 10;
  if(l > r) swap(l, r);
  FILE *f = fopen("inGen", "w");
  fprintf(f, "%d %d %d %d\n", n, q, l, r);
  for(int i = 0; i < q; ++i) {
    int op, x, y;
    op = rand() % 2 + 1;
    if(op == 1) {
      x = rand() % n + 1;
      y = rand() % 10;
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
  for(int i = 0; i < q; ++i) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if(op == 1) v[x] = y;
    else {
      printf("%lld\n", query(x, y));
    }
  }

  for(int i = 1; i <= n; ++i) printf("%d ", v[i]);
  printf("\n");
  return 0;
}