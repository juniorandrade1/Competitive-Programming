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

const int N = 1e5 + 10;

int t;
char s[N];
char op[] = {'C','E','S'};

inline void main2() {
  scanf(" %s", s);
  int len = strlen(s);
  int j = 0;
  for(int i = 0; i < 3; ++i) {
    while(j < len && s[j] == op[i]) j++;
  }
  puts((j == len) ? "yes" : "no");
}

int main() {
  scanf("%d", &t);
  while(t--) main2();
  return 0;
}
