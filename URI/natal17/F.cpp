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

const int N = 100010;

char a[N], b[N];

inline void main2() {
  scanf(" %[^\n] %[^\n]", a, b);
  int la = strlen(a);
  int lb = strlen(b);
  for(int i = 0; i + 1 < la; i += 2) {
    printf("%c%c", a[i], a[i + 1]);
    if(i < lb) printf("%c", b[i]);
    if(i + 1 < lb) printf("%c", b[i + 1]);
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}