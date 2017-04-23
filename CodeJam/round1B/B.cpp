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

const int N = 1010;
int test = 1;

map< pair<char, char>, int > nop;

char s[N];
int n;

bool solve(int len, int r, int o, int y, int g, int b, int v, int fst) {
  if(len == n) {
    if(s[len - 1] == s[0]) return false;
    for(int i = 0; i < n; ++i) printf("%c", s[i]);
    printf("\n");
    return true;
  }
  if(s[len - 1] == 'R') {
    if(y == 0 && b == 0) return false;
    if(y > b || (y == b && fst == 1)) {
      s[len] = 'Y';
      return solve(len + 1, r, o, y - 1, g, b, v, fst);
    }
    else {
      s[len] = 'B';
      return solve(len + 1, r, o, y, g, b - 1, v, fst);
    }
  }
  else if(s[len - 1] == 'Y') {
    if(r == 0 && b == 0) return false;
    if(r > b || (r == b && fst == 0)) {
      s[len] = 'R';
      return solve(len + 1, r - 1, o, y, g, b, v, fst);
    }
    else {
      s[len] = 'B';
      return solve(len + 1, r, o, y, g, b - 1, v, fst);
    }
  }
  else if(s[len - 1] == 'B') {
    if(y == 0 && r == 0) return false;
    if(y > r || (y == r && fst == 1)) {
      s[len] = 'Y';
      return solve(len + 1, r, o, y - 1, g, b, v, fst);
    }
    else {
      s[len] = 'R';
      return solve(len + 1, r - 1, o, y, g, b, v, fst);
    }
  }

  return false;
}

int r, o, y, g, b, v;



inline void main2() {
  scanf("%d %d %d %d %d %d %d", &n, &r, &o, &y, &g, &b, &v);
  printf("Case #%d: ", test++);
  if(r) {
    s[0] = 'R';
    if(solve(1, r - 1, o, y, g, b, v, 0)) return;
  }
  if(y) {
    s[0] = 'Y';
    if(solve(1, r, o, y - 1, g, b, v, 1)) return;
  }
  if(b) {
    s[0] = 'B';
    if(solve(1, r, o, y, g, b - 1, v, 2)) return;
  }
  puts("IMPOSSIBLE");
}

int main() {
  nop[mp('R', 'R')] = 1;
  nop[mp('Y', 'Y')] = 1;
  nop[mp('B', 'B')] = 1;
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}