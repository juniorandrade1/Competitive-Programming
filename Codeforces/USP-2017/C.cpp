#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int N = 500010;

int divisor[N];
int n, q;
int v[N];
vector< int > divs[N];

void crivo() {
  for(int i = 2; i < N; ++i) {
    if(!divisor[i]) {
      for(int j = 1; j * i < N; ++j) if(divisor[i * j] == 0) divisor[i * j] = i;
    }
  }
}

vector< int > primeFactors(int x) {
  vector< int > all;
  while(x > 1) {
    all.pb(divisor[x]);
    x /= divisor[x];
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  return all;
}

int tr[4 * N];

void build(int no, int l, int r, int v[]) {
  if(l == r) {
    tr[no] = v[l];
    return;
  }
  int nxt = (no << 1), md = (l + r) >> 1;
  build(nxt, l, md, v); build(nxt | 1, md + 1, r, v);
  tr[no] = max(tr[nxt], tr[nxt | 1]);
}

int query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), md = (l + r) >> 1;
  return max(query(nxt, l, md, i, j), query(nxt | 1, md + 1, r, i, j));
}

int prev[N];

int main() {
  crivo();
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  for(int i = 1; i <= n; ++i) {
    vector< int > foo = primeFactors(v[i]);
    int sz = foo.size();
    int lo = 1, hi = i;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      int sum = 0;
      for(int mask = 1; mask < (1 << sz); ++mask) {
        int bar = 1;
        for(int j = 0; j < sz; ++j) if((mask >> j) & 1) bar *= foo[j];
        sum += ((divs[bar].end() - lower_bound(divs[bar].begin(), divs[bar].end(), i - md)) * ((__builtin_popcount(mask) & 1) ? 1 : -1));
      }
      if(sum == md) lo = md + 1;
      else hi = md;
    }
    if(i - lo > 0) prev[i] = i - lo;
    for(int mask = 1; mask < (1 << sz); ++mask) {
      int bar = 1;
      for(int j = 0; j < sz; ++j) if((mask >> j) & 1) bar *= foo[j];
      divs[bar].pb(i);
    }
  }
  build(1, 1, n, prev);
  while(q--) {
    int l, r; scanf("%d %d", &l, &r);
    printf("%c\n", query(1, 1, n, l, r) >= l ? 'S' : 'N');
  }
  return 0;
}