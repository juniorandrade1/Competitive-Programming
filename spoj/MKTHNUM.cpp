#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];

struct wavelet {
  int lo, hi;
  wavelet *l, *r;
  vector< int > b;
  wavelet(vector< int > &arr, int x, int y) {
    lo = x; hi = y;
    if(lo == hi || arr.size() == 0) return;
    int md = (lo + hi) >> 1;
    b.push_back(0);
    vector< int > lft, rgt;
    for(int i = 0; i < arr.size(); ++i) {
      if(arr[i] <= md) lft.push_back(arr[i]);
      else rgt.push_back(arr[i]);
      b.push_back(b.back() + (arr[i] <= md));
    }
    l = new wavelet(lft, lo, md);
    r = new wavelet(rgt, md + 1, hi);
  }
  int kth(int l, int r, int k) {
    if(l > r) return 0;
    if(lo == hi) return lo;
    int inLeft = b[r] - b[l - 1];
    int lb = b[l - 1];
    int rb = b[r];
    if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
    else this->r->kth(l - lb, r - rb, k - inLeft);
  }
};

int main() {
  scanf("%d %d", &n, &m);
  vector<int>va;
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    va.push_back(a[i]);
  }
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  for(int i = 0; i < n; ++i) a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
  vector< int > arr;
  for(int i = 0; i < n; ++i) arr.push_back(a[i]);
  wavelet T(arr, 0, va.size());
  while(m--)  {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    printf("%d\n", va[T.kth(l, r, k)]);
  }
  return 0;
}