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



int main() {
  int n; scanf("%d", &n);
  int day = 0;
  for(int i = 0; i < n; ++i) {
    int s, d; scanf("%d %d", &s, &d);
    day++;
    if(day <= s) day = s;
    int q = (day - s + d - 1) / d;
    day = (s + d * q);
  }
  printf("%d\n", day);

  return 0;
}