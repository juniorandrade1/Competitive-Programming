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

const int N = 101;

int h1, a1, c1, h2, a2;


int main() {
  scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
  vector< string > ans;

  int atH = h1;
  while(h2 > 0) {
    if(h2 - a1 <= 0) {
      ans.pb("STRIKE");
      h2 -= a1;
    }
    else if(atH - a2 <= 0) {
      ans.pb("HEAL");
      atH += c1;
    }
    else {
      ans.pb("STRIKE");
      h2 -= a1;
    } 
    if(h2 <= 0) break;
    atH -= a2;
  }


  printf("%d\n", (int)ans.size());
  for(int i = 0; i < ans.size(); ++i) {
    printf("%s\n", ans[i].c_str());
  }
  return 0;
}