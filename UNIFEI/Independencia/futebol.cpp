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


char s[123456];
map<string, int> pont;
string o;
int p;

void parse() {
  o = "";
  p = 0;
  int len = strlen(s);
  int px = 0;
  while(s[px] != '-') px++;
  for(int i = 0; i + 1 < px; ++i) o.pb(s[i]);
  for(int i = px + 1; i < len; ++i) {
    if(s[i] >= '0' && s[i] <= '9') {
      p *= 10;
      p += s[i] - '0';
    }
  }
}

int main() {
  int n; 
  scanf("%d", &n);
  vi anos;
  pont.clear();
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    anos.pb(x);
    for(int j = 0; j < 20; ++j) {
      scanf(" %[^\n]", s);
      parse();
      pont[o] += p;
    }
  }
  vector< pair<int, string> > all;
  for(map<string, int>::iterator it = pont.begin(); it != pont.end(); it++) {
    all.pb(mp(-it->S, it->F));
  }
  printf("Os 10 melhores do ano de");
  for(int i = 0; i < anos.size(); ++i) {
    if(i + 1 < anos.size()) {
      if(i > 0) printf(",");
    }
    else if(anos.size() >= 2) printf(" e");
    printf(" %lld", anos[i]);
  }
  printf(":\n");
  sort(all.begin(), all.end());
  for(int i = 0; i < 10; ++i) {
    printf("%d - %s - %d\n", i + 1, all[i].S.c_str(), -all[i].F);
  }
  return 0;
}