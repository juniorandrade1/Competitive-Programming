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

#define pi acos(-1.0)

const int N = 100001;

int n;
int a[N], b[N];

int main() {
  scanf("%d", &n);
  int qtd = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    qtd += (a[i] < 0);
  }
  puts(qtd <= 1 || qtd >= n - 1 ? "Yes" : "No");
  return 0;
}