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

const int N = 101;

char s[N];
int n;
set<string>foo;

int main() {
  scanf(" %s", s);
  n = strlen(s);
  for(int i = 0; i < n; ++i) {
    string at = "";
    for(int j = 0; j < n; ++j) {
      at.pb(s[(i + j) % n]);
    }
    foo.insert(at);
  }
  printf("%d\n", (int)foo.size());
  return 0;
}