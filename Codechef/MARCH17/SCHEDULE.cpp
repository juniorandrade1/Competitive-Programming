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
 
const int N = 1e6 + 10;
 
char s[N];
char c[N];
int n, k;
 
inline bool test(int blockSize) {
  int kk = 0;
  for(int i = 0; i < n; ++i) c[i] = s[i];
  for(int i = 0; i < n; ++i)  {
    int j = i;
    while(j < n && c[i] == c[j] && j - i + 1 <= blockSize) j++;
    int t = j - i + 1;
    if(t == blockSize + 1 && i + blockSize < n && c[i + blockSize] == c[i]) {
      if(i + blockSize + 1 == n || blockSize == 1) {
        c[i + blockSize] = (c[i + blockSize] == '0') ? '1' : '0';
        i = i + blockSize - 1;
      }
      else if(s[i + blockSize + 1] != s[i]) {
        c[i + blockSize - 1] = (c[i + blockSize - 1] == '0') ? '1' : '0';
        i = i + blockSize - 2;
      }
      else {
         c[i + blockSize] = (c[i + blockSize] == '0') ? '1' : '0';
        i = i + blockSize - 1;
      }
      kk++;
    }
    else i = j - 1;
  }
  return kk <= k;
}
 
int minBlock;
 
inline int go() {
  int at = 0;
  for(int i = 0; i < n; ++i) {
    int j = i;
    while(j < n && c[i] == c[j]) j++;
    at = max(at, j - i);
  }
  return at;
}
 
void gen(int pos, int qtd) {
  if(qtd > k) return;
  if(pos == n) {
    minBlock = min(go(), minBlock);
    return;
  }
  c[pos] = s[pos];
  gen(pos + 1, qtd);
  c[pos] = (s[pos] == '0') ? '1' : '0';
  gen(pos + 1, qtd + 1);
}
 
inline void bruteSolve() {
  minBlock = INF;
  gen(0, 0);
  printf("%d\n", minBlock);
}
 
inline void main2() {
  scanf("%d %d", &n, &k);
  scanf(" %s", s);
  if(n <= 10) bruteSolve();
  else {
    int lo = 1, hi = n;
    while(lo < hi) {
      int mid = (lo + hi) >> 1;
      if(!test(mid)) lo = mid + 1;
      else hi = mid;
    }
    printf("%d\n", lo);
  }
}
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}   