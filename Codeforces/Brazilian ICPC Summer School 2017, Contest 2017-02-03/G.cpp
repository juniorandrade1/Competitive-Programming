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

const int N = 1e5 + 10;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

char s[N];
int n;

inline void main2() {
  scanf(" %s", s);
  n = strlen(s);  
  if(s[n - 2] == 'c' && s[n - 1] == 'h') {
    printf("%ses\n", s);
  } 
  else if(s[n - 1] == 'x' || s[n - 1] == 's' || s[n - 1] == 'o') {
    printf("%ses\n", s);
  }
  else if(s[n - 1] == 'f') {
    for(int i = 0; i + 1 < n; ++i) printf("%c", s[i]);
    printf("ves\n");
  }
  else if(s[n - 2] == 'f' && s[n - 1] == 'e') {
    for(int i = 0; i + 2 < n; ++i) printf("%c", s[i]);
    printf("ves\n");
  }
  else if(s[n - 1] == 'y') {
    for(int i = 0; i + 1 < n; ++i) printf("%c", s[i]);
    printf("ies\n");
  }
  else printf("%ss\n", s);
}

int main() {
  arquivo();
  int t; scanf("%d", &t);
  while(t--) {
    main2();
  }
  return 0;
}