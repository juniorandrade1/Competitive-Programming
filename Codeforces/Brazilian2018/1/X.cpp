#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set< ll > s;

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    ll x; scanf("%lld", &x);
    s.insert(x);
  }
  vector< ll > sol;
  for(set< ll >::iterator it = s.begin(); it != s.end(); it++) sol.push_back(*it);
  int sz = sol.size();
  if(n % 2 == 0) {
    for(int i = sz - 1; i >= 0; --i) printf("%lld\n", sol[i]);
  }
  else {
    for(int i = 0; i < sz; ++i) printf("%lld\n", sol[i]);
  }
  return 0;
}