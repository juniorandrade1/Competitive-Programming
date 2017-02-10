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

char s[N];
int n;
// Encontrar palindromos - inicializa d1 e d2 com zeros, e eles guadram
// o numero de palindromos centrados na posicao i (d1[i] e d2[i])
int d1[N], d2[N];
void imp(){
  int l=0, r=-1;
  for(int i = 0; i < n; ++i) d1[i] = 0;
  for (int i=0; i<n; ++i) {
    int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) ++k;
    d1[i] = --k;
    if (i+k > r) l = i-k, r = i+k;
  }
}

void par(){
  int l=0, r=-1;
  for(int i = 0; i < n; ++i) d2[i] = 0;
  for (int i=0; i<n; ++i) {
    int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k]) ++k;
    d2[i] = --k;
    if (i+k-1 > r) l = i-k, r = i+k-1;
  }
}


int main() {
  while(scanf(" %s", s) != EOF) {
    n = strlen(s);
    imp();
    par();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      if(d2[i] == i) ans = max(ans, d2[i] * 2);
      if(d1[i] == i) ans = max(ans, d1[i] * 2 + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}