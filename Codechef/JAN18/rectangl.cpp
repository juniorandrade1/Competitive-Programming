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

inline void main2() {
  vi s;
  for(int i = 0; i < 4; ++i) {
    int x; scanf("%d", &x);
    s.pb(x);
  }
  sort(s.begin(), s.end());
  puts(s[0] == s[1] && s[2] == s[3] ? "YES" : "NO");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}