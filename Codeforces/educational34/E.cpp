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

const int N = 5050;

int n;
int v[N];
int ok[N];

void go(int x) {
  ok[x] = 1;
  for(int i = x + 1; i < n; ++i) {
    if(ok[i]) continue;
    if(v[x] > v[i]) {
      go(i);
      return;
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  sort(v, v + n);
  reverse(v, v + n);
  int qtd = 0;
  for(int i = 0; i < n; ++i) {
    if(ok[i]) continue;
    qtd++;
    go(i);
  }
  printf("%d\n", qtd);
  return 0;
}