#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif


void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

const int N = 606;

int n, k;
ll f[N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i + 1 < n; ++i) {
    for(int j = i; j + 1 < n; ++j) {
      ll x; scanf("%lld", &x);
      f[j] += x;
    }
  }
  pq< ii > q; 
  for(int j = 0; j + 1  < n; ++j) {
    q.push(ii(f[j], j));
  }
  vi sol;
  while(!q.empty() && k) {
    k--;
    sol.pb(q.top().S);
    q.pop();
  }
  sort(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i) {
    printf("%lld ", sol[i]);
  }
  printf("\n");
  return 0;
}