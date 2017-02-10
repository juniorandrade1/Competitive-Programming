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

const int N = 1e3 + 10;

int L[N], R[N], V[N];
int n;
int ans = 0;

void go(int x, int value, int prof) {
  ans = max(ans, prof);
  if(V[x] >= V[value]) {
    if(L[x] != -1) go(L[x], value, prof + 1);
    else L[x] = value;
  }
  else {
    if(R[x] != -1) go(R[x], value, prof + 1);
    else R[x] = value;
  }
}

int main() {
  memset(L, -1, sizeof L);
  memset(R, -1, sizeof R);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {  
    scanf("%d", V + i);
    if(i) go(0, i, 1);
  }
  printf("%d\n", ans + 1);
  return 0;
}