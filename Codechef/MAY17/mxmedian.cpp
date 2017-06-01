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

const int N = 100010;

int n;
int v[N];
int a[N];
int b[N];

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < 2 * n; ++i) scanf("%d", v + i);
  sort(v, v + 2 * n);
  for(int i = 0; i < n; ++i) {
    a[i * 2] = v[i];
    a[i * 2 + 1] = v[2 * n - i - 1];
    b[i] = max(a[i * 2], a[i * 2 + 1]);
  }    
  sort(b, b + n);
  printf("%d\n", b[n / 2]);
  for(int i = 0; i < 2 * n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}
