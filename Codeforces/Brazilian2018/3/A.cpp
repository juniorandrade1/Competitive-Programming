
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


const int N = 110;

int n;
char s[N], t[N];
map< string, int > qtd;
vector< pair<string, string> > sol;

int main() {
  while(scanf("%d", &n) != EOF) {
    qtd.clear();
    sol.clear();
    for(int i = 0; i < n; ++i) {
      scanf(" %s %s", s, t);
      if(strcmp("SCH", s) == 0)  continue;
      qtd[(string)s]++;
      if(strcmp(s, "MSU") == 0) {
        if(qtd[(string)s] <= 4) sol.pb(mp((string)s, (string)t));
      }
      else {
        if(qtd[(string)s] <= 2) sol.pb(mp((string)s, (string)t));
      }
    }
    int n = min((int)sol.size(), 10);
    printf("%d\n", n);
    for(int i = 0; i < (int)n; ++i) {
      printf("%s %s\n", sol[i].F.c_str(), sol[i].S.c_str());
    }
  }
  return 0;
}