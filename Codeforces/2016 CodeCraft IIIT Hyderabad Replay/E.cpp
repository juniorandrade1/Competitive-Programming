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
#define eps 1e-6

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1010;

int n, m;

inline void main2() {
  scanf("%d %d", &n, &m);
  bool sol = 0;
  for(int i = 0; i < m; ++i) {
    int x, y; scanf("%d %d", &x, &y);
    if(x == 1 && y == n) sol = 1;
  }
  puts(sol ? "Jorah Mormont" : "Khal Drogo");

}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}