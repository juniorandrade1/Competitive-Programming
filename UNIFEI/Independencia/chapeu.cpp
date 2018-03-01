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
char p[123456];
string all[] = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};


int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    map<string, vector<string> > cnt;
    for(int i = 0; i < n; ++i) {
      scanf(" %[^\n]", s);
      scanf(" %[^\n]", p);
      cnt[(string)p].pb((string)s);
    }
    for(int i = 0; i < 4; ++i) {
      string lol = all[i];
      printf("%s:\n", lol.c_str());
      sort(cnt[lol].begin(), cnt[lol].end());
      for(int j = 0; j < cnt[lol].size(); ++j) printf("%s\n", cnt[lol][j].c_str()); 

      printf("\n");
    }
  }
  return 0;
}