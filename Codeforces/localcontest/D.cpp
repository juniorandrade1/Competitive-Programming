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

int getVal(char c) {
  if(c == 'A' || c == 'B' || c == 'C') return 2;
  if(c == 'D' || c == 'E' || c == 'F') return 3;
  if(c == 'G' || c == 'H' || c == 'I') return 4;
  if(c == 'J' || c == 'K' || c == 'L') return 5;
  if(c == 'M' || c == 'N' || c == 'O') return 6;
  if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') return 7;
  if(c == 'T' || c == 'U' || c == 'V') return 8;
  if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z') return 9;
}

inline bool solve(string s) {
  int n = s.size();
  int i = 0, j = n - 1;
  while(i < j) {
    if(getVal(toupper(s[i])) != getVal(toupper(s[j]))) {
      return false;
    }
    i++; j--;
  }
  return true;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    char s[20];
    scanf(" %s", s);
    printf("%s\n", (solve((string)s) ? "YES" : "NO"));
  }
  return 0;
}