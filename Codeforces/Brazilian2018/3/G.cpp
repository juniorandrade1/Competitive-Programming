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

const int N = 1100;

int n;
int x[N], y[N];
map< ii, int > q;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", x + i, y + i);
  }
  if(n <= 3) {
    puts("0");
    return 0;
  }
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      // (x[i] + x[j]) / 2 == (x'[i] + x'[j]) / 2 => (x[i] + x[j]) == (x'[i] + x'[j])
      q[ii(x[i] + x[j], y[i] + y[j])]++;
      if(q[ii(x[i] + x[j], y[i] + y[j])] >= 2) {
        puts("1");
        return 0;
      }
    }
  }

  puts("2");
  return 0;
}