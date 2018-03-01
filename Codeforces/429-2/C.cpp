#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

#define F first
#define S second

typedef pair<int,int>ii;

int n;
ii a[N], b[N];
int sol[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a[i].F);
    a[i].S = i;
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", b[i].F);
    b[i].S = i;
  }

  sort(a, a + n);
  sort(b, b + n);

  multiset< ii > s;

  for(int i = 0; i < n; ++i) {
    s.insert(b[i]);
  }

  for(int i = n - 1; i >= 0; --i) {
    int d = a[i].F / 2LL;
    multiset< ii > :: iterator it1 = s.lower_bound(ii(d, N + 1));
    if(it1 != s.begin()) it1--;
    sol[a[i].S] = it1->F;
    s.erase(it1);
  }

  for(int i = 0; i < n; ++i) printf("%d ", sol[i]);
  printf("\n");
  return 0;
}