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

const int N = 1e5 + 10;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int n;
ll v[N];

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  ll s = v[0];
  for(int i = 1; i < n; ++i) s ^= (v[i] * (v[i] - v[i - 1]));
  printf("%lld\n", s);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}