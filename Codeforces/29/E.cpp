#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int N = 3000020;

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

void update(int no, int l, int r, int i, int j, int val) {
  propagate(no, l, r);
  if(r < i || l > j) return;
  if(l >= i && r <= j) {
    lz[no] += val;
    propagate(no, l, r);
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  update(nxt, l, mid, i, j, val);
  update(nxt + 1, mid + 1, r, i, j, val);
  tr[no] = min(tr[nxt], tr[nxt + 1]);
}

int query(int no, int l, int r, int i, int j) {
  propagate(no, l, r);
  if(r < i || l > j) return INF;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return min(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

int n;
int L[N], R[N];
vector<int> all;

int main() {
  scanf("%d", &n);
  if(n == 1) {
    puts("-1");
    exit(0);
  }
  int mn = INF, mx = -INF;
  for(int i = 1; i <= n; ++i) {
    scanf("%d %d", L + i, R + i);
    all.push_back(L[i] - 1);
    all.push_back(L[i]);
    all.push_back(L[i] + 1);
    all.push_back(R[i] - 1);
    all.push_back(R[i]);
    all.push_back(R[i] + 1);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());

  int sz = all.size();
  for(int i = 1; i <= n; ++i) {
    L[i] = lower_bound(all.begin(), all.end(), L[i]) - all.begin();
    R[i] = lower_bound(all.begin(), all.end(), R[i]) - all.begin();
    update(1, 0, sz - 1, L[i], R[i], 1);
  }

  for(int i = 1; i <= n; ++i) {
    if(query(1, 0, sz - 1, L[i], R[i]) > 1) {
      printf("%d\n", i);
      exit(0);
    }
  }

  puts("-1");
  return 0;
}