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
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 110;

int getVal(char c) {
  if(c == 'R') return 0;
  if(c == 'B') return 1;
  if(c == 'Y') return 2;
  if(c == 'G') return 3;
}

char s[N];
int n;
int type[4];
int qtd[4];

int main() {
  scanf(" %s", s);
  n = strlen(s);
  for(int i = 0; i < n; ++i) {
    if(s[i] == '!') {
      qtd[i % 4]++;
    }
    else {
      type[getVal(s[i])] = i % 4;
    }
  }

  for(int i = 0; i < 4; ++i) printf("%d ", qtd[type[i]]);

  return 0;
}