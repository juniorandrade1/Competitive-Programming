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

const int N = 1001;

int pd[N];
int a[N], b[N];
int n;

inline void main2() {
  memset(pd, 0, sizeof pd);

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
  }
  int m; scanf("%d", &m);
  for(int i = 1; i <= m; ++i) pd[i] = -INF;
  for(int i = 0; i < n; ++i) {
    for(int j = m; j >= b[i]; --j) pd[j] = max(pd[j], pd[j - b[i]] + a[i]);
  }
  int sol = *max_element(pd, pd + m + 1);
  int r; scanf("%d", &r);
  if(sol >= r) printf("A resistencia do castelo %d nao suportou o ataque da missao %d\n", r, sol);
  else printf("Missao falhou\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}