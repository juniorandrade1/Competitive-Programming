#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100001;

ll q;
int n;
ll v[N];
ll p[N];

bool cmp(ll a, ll b) {
  return q % v[a] < q % v[b];
}

int main() {
  scanf("%lld %d", &q, &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", v + i);
    p[i] = i;
  }
  sort(p, p + n, cmp);
  printf("%lld %lld\n", p[0] + 1, q / v[p[0]]);
  return 0;
}