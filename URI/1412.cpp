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
int n;
int pd[N][26];

int func(int pos, int rot) {
  if()
}

int main() {
  while(scanf(" %s", s) != EOF) {
    if(s[0] == '*') break;
    n = strlen(s);
    memset(pd, -1, sizeof pd);
    printf("%d\n", func(0, 0));
  }
  return 0;
}