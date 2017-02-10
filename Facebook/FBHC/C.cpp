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
#define PI acos(-1)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 11;

int a[] = {4, 6, 8, 10, 12, 20};
int inv[21];


int h, n;
vii range;
char s[12345];

short memo[8][25][53300];
double pd[8][25][53300];

double get(int type, int jog, int qtd) {
  if(qtd <= 0) return 1;
  if(jog == 0) return 0;
  if(memo[type][jog][qtd]) return pd[type][jog][qtd];
  double ret = 0;
  for(int i = 1; i <= a[type]; ++i) ret += get(type, jog - 1, qtd - i);
  ret /= (double)a[type];
  memo[type][jog][qtd] = 1;
  return pd[type][jog][qtd] = ret;
}


inline double parseString() {
  assert(s[0] != '+' && s[0] != '-');
  int len = strlen(s);
  int gap = 0;
  for(int i = len - 1; i >= 0; --i) {
    if(s[i] == '+' || s[i] == '-') {
      int sig = s[i] == '+' ? 1 : -1;
      for(int j = i + 1; j < len; ++j) gap *= 10, gap += s[j] - '0';
      gap *= sig;
      len = i;
      break;
    }
  }
  int X = 0, Y = 0;
  int i = 0;
  for(i = 0; i < len; ++i) {
    if(s[i] == 'd') break;
    X *= 10; X += s[i] - '0';
  }
  i++;
  for(; i < len; ++i) {
    Y *= 10;
    Y += s[i] - '0';
  }

  return get(inv[Y], X, h - gap);
}

inline void main2(int testCase) {
  scanf("%d %d", &h, &n);
  range.clear();
  double ans = 0.0000000;
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    ans = max(ans, parseString());
  }
  printf("Case #%d: %.6lf\n", testCase, ans);
}

int main() {
  for(int i = 0; i < 6; ++i) inv[a[i]] = i; 


  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) main2(i); 
  return 0;
}