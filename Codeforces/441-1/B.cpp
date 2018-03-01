#include <bits/stdc++.h>

using namespace std;

const int N = 300030;

int pset[N], sizeSet[N];

int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }

void unionSet(int i, int j) {
  if(sizeSet[findSet(i)] < sizeSet[findSet(j)]) swap(i, j);
  int pi = findSet(i), pj = findSet(j);
  sizeSet[pi] += sizeSet[pj]; sizeSet[pj] = 0;
  pset[pj] = pi;
}

void initSet(int n) { 
  for(int i = 0; i <= n; ++i) {
    pset[i] = i;
    sizeSet[i] = 1;
  }
}

int n;
int v[N];

int main() {
  scanf("%d", &n);
  initSet(n + 1);
  int qtd = 1;
  printf("%d", qtd);
  for(int i = 1; i <= n; ++i) {
    qtd++;
    scanf("%d", v + i);
    int foo = sizeSet[findSet(v[i])];
    unionSet(v[i], v[i] + 1);
    if(findSet(v[i]) == findSet(n + 1)) qtd -= foo;
    printf(" %d", qtd);
  }
  printf("\n");
  return 0;
}