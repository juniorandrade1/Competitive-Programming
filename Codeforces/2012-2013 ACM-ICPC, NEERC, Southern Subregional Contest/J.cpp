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

int n, a, b, c;
char s[1234567];

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int main() {
  arquivo();
  scanf("%d %d %d", &n, &a, &b);
  scanf(" %s", s);
  c = n - a - b;
  if(c < 0) {
    puts("-1");
    exit(0);
  }
  int ca, cb, cc;
  ca = cb = cc = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '0') ca++;
    if(s[i] == '1') cb++;
    if(s[i] == '2') cc++;
  }
  int qtd = 0;
  for(int i = 0; i < n; ++i) {
    if(ca > a && s[i] == '0') {
      if(cb < b) {
        cb++;
        s[i] = '1';
      }
      else if(cc < c) {
        cc++;
        s[i] = '2';
      }
      qtd++;
      ca--;
    }

    if(cb > b && s[i] == '1') {
      qtd++;
      if(ca < a) {
        ca++;
        s[i] = '0';
      }
      else if(cc < c) {
        cc++;
        s[i] = '2';
      }
      cb--;
    }

    if(cc > c && s[i] == '2') {
      qtd++;
      if(cb < b) {
        cb++;
        s[i] = '1';
      }
      else if(ca < a) {
        ca++;
        s[i] = '0';
      }
      cc--;
    }
  }
  printf("%d\n%s\n", qtd, s);
  return 0;
}