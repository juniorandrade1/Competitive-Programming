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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1e5 + 10;



inline void main2(int testCase) {
  double x, y, p; scanf("%lf %lf %lf", &p, &x, &y);
  x -= 50;
  y -= 50;
  if(p == 0) {
    printf("Case #%d: white\n", testCase);
    return;
  }
  if(x == 0 && y == 0) {
    printf("Case #%d: black\n", testCase);
    return;
  }
  double ang = atan2(y, x) * 180 / PI;
  double d = hypot(x, y);
  if(ang > p * 3.6 || d > 50) printf("Case #%d: white\n", testCase);
  else printf("Case #%d: black\n", testCase);
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) main2(i); 
  return 0;
}