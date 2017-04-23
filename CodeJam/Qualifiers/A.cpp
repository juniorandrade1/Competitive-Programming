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

const int N = 1010;

char s[N];
int n, k;

inline void main2(int _test) {
  scanf(" %s %d", s, &k);
  n = strlen(s);
  int qtd = 0;
  for(int i = 0; i + k - 1 < n; ++i) {
    if(s[i] == '-') {
      qtd++;
      for(int j = 0; j < k; ++j) s[i + j] = (s[i + j] == '-')  ? '+' : '-';
    }
  }
  for(int i = 0; i < n; ++i) {
    if(s[i] == '-') {
      printf("Case #%d: IMPOSSIBLE\n", _test);
      return;
    }
  }
  printf("Case #%d: %d\n", _test, qtd);
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}