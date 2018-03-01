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

const int N = 10010;
const int GAP = 5;

int n;
int v[N];
int pd[N][2 * GAP];

int func(int pos, int qtd) {
  if(abs(qtd - GAP) > 5) return 0;
  if(pos == n) return 1;
  if(pd[pos][qtd] != -1) return pd[pos][qtd];
  return pd[pos][qtd] = (func(pos + 1, qtd - v[pos]) | func(pos + 1, qtd + v[pos])); 
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  memset(pd, -1, sizeof pd);
  puts(func(0, GAP) ? "Feliz Natal!" : "Ho Ho Ho!");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}