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

const int N = 100010;

int n, q;
int server[N];

void can(int t, int d, int k) {
  int qtd = 0;
  for(int i = 0; i < n; ++i) {
    if(server[i] < t) qtd++;
  }
  if(qtd < k) puts("-1");
  else  {
    int e = t + d - 1;
    int sol = 0;
    for(int i = 0; i < n && k; ++i) {
      if(server[i] < t) {
        server[i] = e;
        sol += i + 1;
        k--;
      }
    }
    printf("%d\n", sol);
  }
}

int main() {
  scanf("%d %d", &n, &q);
  int sol = 0;
  for(int i = 0; i < q; ++i) {
    int t, d, k;
    scanf("%d %d %d", &t, &k, &d);
    can(t, d, k);
  }
  return 0;
}