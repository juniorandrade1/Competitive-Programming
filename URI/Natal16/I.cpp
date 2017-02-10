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
const int N = 12345;
char s1[N], s2[N];
map<string, string> id;

int main() {
  int n; scanf("%d", &n);
  while(n--) {
    scanf(" %[^\n] %[^\n]", s1, s2);
    id[(string)s1] = s2;
  }
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %[^\n] %[^\n]", s1, s2);
    printf("%s\n%s\n\n", s1, id[(string)s2].c_str());
  }  
  return 0;
}