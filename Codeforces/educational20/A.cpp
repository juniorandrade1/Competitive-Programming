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

const int N = 101;

int n, k;
int v[N][N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(v[i][j] == 1) continue;
      if(i == j && k >= 1) {
        v[i][j] = 1;
        k--;
      }
      else if(k >= 2) {
        v[i][j] = 1;
        if(i <= j) {
          v[j][i] = 1;
        }
        else {
          debug("NOP");
        }
        k -= 2;
      }
    }
  }
  if(k) puts("-1");
  else {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        printf("%d ", v[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
