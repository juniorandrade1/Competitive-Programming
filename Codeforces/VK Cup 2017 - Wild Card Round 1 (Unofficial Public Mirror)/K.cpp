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

const int N = 100010;

char vog[] = {'a','e','i','o','u','y'};
int rep[6];

char s[N];
int n;

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  for(int i = 0; i < n; ++i) {
    int j = 0;
    for(j = 0; j < 6; ++j) if(vog[j] == s[i]) break;
    if(j == 6) {
      printf("%c", s[i]);
    }
    else {
      int is = (j == 1 || j == 3);
      j = i;
      while(j < n && s[i] == s[j]) j++;
      printf("%c", s[i]);
      if(is && (j - i) == 2) printf("%c", s[i]);
      i = j - 1;
    }
  }
  printf("\n");
  return 0;
}