#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

typedef long long ll;

int is[N], p[N], sz = 0;

void sieve() {
  for(int i = 2; i < N; ++i) {
    if(!is[i]) {
      p[sz++] = i;
      for(int j = 1; j * i < N; ++j) is[i * j] = i;
    }
  }
}

map< ll, bool > vis;

int main() {
  sieve();
  ll n; scanf("%lld", &n);
  priority_queue< ll > q; 
  for(int i = 0; i < sz; ++i) {
    q.push(-(1ll * p[i] * p[i]));
    vis[p[i] * p[i]] = 1;
  }
  while(1) {
    n--;
    ll x = -q.top(); q.pop();
    printf("-> %lld\n", x);
    if(n == 0) {
      printf("%lld\n", x);
      break;
    }
    for(int i = 0; i < sz; ++i) {
      ll y = x * p[i];
      if(!vis[y]) {
        vis[y] = 1;
        q.push(-y);
      }
    }
  }
  return 0;
}