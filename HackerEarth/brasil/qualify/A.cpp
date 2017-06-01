#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, k;
int a[N];
int tr[4 * N];

void update(int no, int l, int r, int i, int v) {
  tr[no] += v;
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, v);
  else update(nxt + 1, mid + 1, r, i, v);
}

int query(int no, int l, int r, int v) {
  if(l == r) return l;
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(tr[nxt] >= v) return query(nxt, l, mid, v);
  else return query(nxt + 1, mid + 1, r, v - tr[nxt]);
}

int main() {
  scanf("%d %d", &n, &k);
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    update(1, 0, 1000000, a[i], 1);
    if(i >= k) update(1, 0, 1000000, a[i - k], -1);
    if(i >= k - 1) ans = max(ans, query(1, 0, 1000000, k / 2 + 1));
  }
  printf("%d\n", ans);
  return 0;
}