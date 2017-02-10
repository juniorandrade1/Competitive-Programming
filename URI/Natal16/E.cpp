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

int n;
map<string, vector< string > >oi;
char a[1234], b[1234], c[1234], d[1234];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) {
      scanf(" %s %s %s %s", a, b, c, d);
      oi[(string)a].pb((string)b);
      oi[(string)a].pb((string)c);
      oi[(string)a].pb((string)d);
    }
    while(scanf(" %s %s", a, b) != EOF) {
      int ok = 0;
      for(int j = 0; j < oi[(string)a].size(); ++j) {
        if((string)b == oi[(string)a][j]) ok = 1;
      }

      puts(ok ? "Uhul! Seu amigo secreto vai adorar o/": "Tente Novamente!");
    }
  }
  return 0;
}