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

const int N = 303;

struct node {
  string s;
  node(){};
  int needClose, open;
  node(string _s) {
    s = _s;
    needClose = 0;
    open = 0;
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == '(') {
        open++;
      }
      else {
        if(open == 0) needClose++;
        else open--;
      }
    }
  }
  bool operator < (node other) const {
    if(open != other.open) return open > other.open;
    return  needClose < other.needClose;
  }
};

int n;
char s[N];
node v[N];
int pd[N][N];
short memo[N][N];

int func(int pos, int gap) {
  if(pos == n) return (gap == 0) ? 0 : -INF;
  if(memo[pos][gap]) return pd[pos][gap];
  int ret = func(pos + 1, gap);
  if(gap - v[pos].needClose >= 0) ret = max(ret, (int)v[pos].s.size() + func(pos + 1, gap + v[pos].open - v[pos].needClose));
  memo[pos][gap] = 1;
  return pd[pos][gap] = ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    v[i] = node((string)s);
  }
  sort(v, v + n);
  printf("%d\n", func(0, 0));
  return 0;
}