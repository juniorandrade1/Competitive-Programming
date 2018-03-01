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

const int N = 100010;

int e[N];
char s[N];

inline void main2() {
  for(int i = 0; i < 10; ++i) e[i] = 0;
  scanf(" %s", s);
  int len = strlen(s);
  for(int i = 0; i < len; ++i) {
    int d = s[i] - '0';
    e[d]++;
  }
  for(char c = 'A'; c <= 'Z'; ++c) {
    int d = (int)c;
    int d0 = d % 10;
    int d1 = ((d / 10) % 10);
    if(d0 == d1) {
      if(e[d0] >= 2) printf("%c", c);
    }
    else {
      if(e[d0] && e[d1]) printf("%c", c);
    }
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}