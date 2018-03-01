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

const int N = 5002;

const int MOD = (int)1e9 + 7LL;

inline void addMod(int &a, int b, int md = MOD) {
  if(a >= md) a -= md;
  if(b >= md) b -= md;
  a += b;
  if(a >= md) a -= md;
}

int n;
int op[N]; 
int pd[N][N];

int func(int pos, int qtd) {
  if(pos == n) return 1;
  if(pd[pos][qtd] != -1) return pd[pos][qtd];
  pd[pos][qtd] = func(pos + 1, qtd + op[pos]);
  if(qtd > 0 && !op[pos - 1]) addMod(pd[pos][qtd], func(pos + 1, qtd - 1));
  return pd[pos][qtd];
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    op[i] = (c == 'f');
  }
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(0, 0));
  return 0;
}