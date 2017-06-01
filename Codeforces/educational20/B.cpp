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

const int N = 200020;

int n, v[N], L[N], R[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", v + i);
  }

  int lst = -INF;
  for(int i = 0; i < n; ++i) {
    if(v[i] == 0) lst = i;
    L[i] = lst;
  }
  lst = INF;
  for(int i = n - 1; i >= 0; --i) {
    if(v[i] == 0) lst = i;
    R[i] = lst;
  }
  for(int i = 0; i < n; ++i) {
    int sol = min(R[i] - i, i - L[i]);
    printf("%d ", sol);
  }
  return 0;
}
