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

const int N = 1e5 + 10;

char s[N];
char p[N];
int sz = 0;

int main() {
  scanf(" %s", s);
  int len = strlen(s);

  int ok = 0;
  int a = 0, b = 0;
  char c;
  for(int i = 0; i < len; ++i) {
    if(s[i] == '*' || s[i] == '-') {
      c = s[i];
      ok = 1;
    }
    else if(s[i] >= 'a' && s[i] <= 'z') p[sz++] = s[i];
    if(s[i] >= '0' && s[i] <= '9') {
      if(ok == 0) {
        a *= 10;
        a += s[i] - '0';
      }
      else {
        b *= 10;
        b += s[i] - '0';
      }
    }
  }

  for(int i = 0; i < sz; ++i) {
    printf("%c", p[i]);
  }
  printf("\n\n");

  for(int i = 0; i < sz; ++i) {
    int id = i;
    for(int j = i; j < sz; ++j) {
      if(p[id] > p[j]) id = j;
    }
    char aux = p[id];
    p[id] = p[i];
    p[i] = aux;
  }


  for(int i = 0; i < sz; ++i) {
    printf("%c", p[i]);
  }
  printf("\n\n");  

  printf("%d %c %d = ", a, c, b);
  if(c == '*') printf("%d\n", a * b);
  else printf("%d\n", a - b);
  return 0;
}
