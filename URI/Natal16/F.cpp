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

char s[123456];
char f;
vector<string>v;

int main() {
  int n; scanf("%d", &n);
  int c = 0;
  for(int i = 0; i < n; ++i) {
    scanf(" %c %s", &f, s);
    if(f == '+') c++;
    v.pb((string)s);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); ++i) printf("%s\n", v[i].c_str());
  printf("Se comportaram: %d | Nao se comportaram: %d\n", c, n - c);
  return 0;
}