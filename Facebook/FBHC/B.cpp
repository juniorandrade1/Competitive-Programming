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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 123;

ll v[N];
int n;

inline void main2(int testCase) {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  reverse(v, v + n);
  int r = n - 1, l = 0;
  int qtd = 0;
  while(l < r) {
    ll p = v[l];
    int need = (50 + p - 1) / p - 1;
    if(need < 0) need = 0;
    r -= need;
    if(r < l) break;
    l++;
    qtd++;
  }
  printf("Case #%d: %d\n", testCase, qtd);  
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) main2(i); 
  return 0;
}