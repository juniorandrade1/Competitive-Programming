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

const int N = 24;

int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int v[N];

inline bool check(int st) {
  bool OK = true;
  for(int i = 0; i < n; ++i) {
    int x = a[(i + st) % 12];
    if(x != 28) OK &= (x == v[i]);
    else OK &= ((x == v[i]) || (x + 1 == v[i]));
  }
  return OK;
}

int main() {
  scanf("%d", &n);
  int q = 0;
  for(int i = 0; i < n; ++i) scanf("%d", v + i), q += v[i] == 29;
  if(q > 1) {
    puts("NO");
    exit(0);
  }
  for(int i = 0; i < 12; ++i) {
    if(check(i)) {
      puts("YES");
      exit(0);
    }
  }
  puts("NO");
  return 0;
}