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

const int N = 1e5 + 10;

int n, a, b;
char s[N];

int main() {
  scanf("%d %d %d", &n, &a, &b);
  scanf(" %s", s);
  a--; b--;
  if(s[a] == s[b]) puts("0");
  else {
    int sol = INF;
    for(int i = a - 1; i >= 0; --i) {
      if(s[i] == s[b]) {
        sol = min(sol, a - i);
        break;
      }
    }
    for(int i = a + 1;  i < n; ++i) {
      if(s[i] == s[b]) {
        sol = min(sol, i - a);
      }
    }
    printf("%d\n", sol);
  }
  return 0;
}