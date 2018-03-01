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

const int N = 500010;

int n;
vector< pair<char, int> > st;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    char c; scanf(" %c", &c);
    int x; scanf("%d", &x);

    bool affect = false;
    
    for(int bit = 0; bit < 10; ++bit) {
      int id = -1;
      for(int j = (int)st.size() - 1; j >= 0; --j) {
        int b = ((st[j].S >> bit) & 1);
        if(st[j].F == '|') {
          if(b) {
            id = j; break;
          }
        }
        else if(st[j].F == '&') {
          if(!b) {
            id = j; break;
          }
        }
        else if(st[j].F == '^') {
          if(b) {
            id = j; break;
          }
        }
      }
      int b = ((x >> bit) & 1);
      if(id == -1) continue;
      if(c != st[id].F) {
        if((c == '^' || c == '|') && b == 0) continue;
        if(c == '&' && b) continue;
      }
      else {
        if(c == '^' && b) {
          st[id].S ^= (b << bit);
          x ^= (1 << bit);
        }
        if(c == '|' && b) {
          st[id].S |= (b << bit);
          x ^= (1 << bit);
        }
        if(c == '&' && !b) {
          st[id].S &= (b << bit);
          x ^= (1 << bit);
        }
      }
    }
    
    if(x == 0 && (c == '|' || c == '^')) continue;
    if(x == (1 << 10) - 1 && (c == '&')) continue;
    st.pb(mp(c, x));
    
  }
  

  printf("%d\n", (int)st.size());
  for(int i = 0; i < st.size(); ++i) printf("%c %d\n", st[i].F, st[i].S);
  
  return 0;
}