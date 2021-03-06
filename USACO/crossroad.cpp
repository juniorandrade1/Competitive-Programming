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
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 101;

int n;
int op[N];

int main() {
  arquivo();
  scanf("%d", &n);
  memset(op, -1, sizeof op);
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    if(op[x] == -1) op[x] = y;
    else if(op[x] != y) cnt++;
    op[x] = y;
  }
  printf("%d\n", cnt);
  return 0;
}