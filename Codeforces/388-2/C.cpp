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

const int N = 200200;

int n;
char s[N];
set<int>op[2];

int main() {
  scanf("%d", &n);
  scanf(" %s", s);

  for(int i = 0; i < n; ++i) {
    if(s[i] == 'R') op[0].insert(i);
    else op[1].insert(i);
  }

  int at = 0;
  int resetCount = 0;
  while(op[0].size() && op[1].size()) {
    set<int>::iterator it1 = op[0].lower_bound(at);
    set<int>::iterator it2 = op[1].lower_bound(at);

    if(it1 == op[0].end() && it2 == op[1].end()) {
      at = 0;
      resetCount++;
    }
    else if(it1 == op[0].end()) {
      at = *it2 + 1;
      op[0].erase(op[0].begin());
    }
    else if(it2 == op[1].end()) {
      at = *it1 + 1;
      op[1].erase(op[1].begin());
    }
    else {
      int d1 = (*it1) - at + 1;
      int d2 = (*it2) - at + 1;
      if(d1 < d2) {
        at = *it1 + 1;
        op[1].erase(it2);
      }
      else {
        at = *it2 + 1;
        op[0].erase(it1);
      }
    }
  }

  puts(op[0].size() ? "R" : "D");
  debug("RESET COUNT = %d\n", resetCount);
  
  return 0;
}