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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

void arquivo() {
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);
}

const int N = 100010;

int n, k, b;
int arr[N];

int main() {
  arquivo();
  scanf("%d %d %d", &n, &k, &b);
  for(int i = 0; i < b; ++i) {
    int x; scanf("%d", &x);
    arr[x] = 1;
  }
  for(int i = 1; i <= n; ++i) arr[i] += arr[i - 1];
  int ans = INF;
  for(int i = k; i <= n; ++i) ans = min(ans, arr[i] - arr[i - k]);
  printf("%d\n", ans);
  return 0;
}