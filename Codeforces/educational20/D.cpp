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

const int N = 1000010;

char s[N];
int k, n;
int cSum[N];
int L[N];

inline bool go(int len) {
  if(n / len > k) return false;
  int pieces = 0;
  int i = 0;
  while(i < n && pieces <= k) {
    pieces++;
    int stp = i + len - 1;
    if(stp >= n - 1) break;
    stp = L[stp];
    if(stp == -1) return false;
    if(cSum[stp] < pieces) return false;
    i = stp + 1;
  }
  return pieces <= k;
}

int main() {
  scanf("%d", &k);
  scanf(" %[^\n]", s);
  n = strlen(s);
  int lst = -1;
  for(int i = 0; i < n; ++i) {
    cSum[i] = (s[i] == '-' || s[i] == ' ');
    if(s[i] == '-' || s[i] == ' ') lst = i;
    L[i] = lst;
    if(i) cSum[i] += cSum[i - 1];
  }
  int lo = 1, hi = n;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(go(mid)) hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}
