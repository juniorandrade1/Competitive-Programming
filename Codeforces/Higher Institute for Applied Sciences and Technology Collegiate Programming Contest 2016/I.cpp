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

char s1[N], s2[N];
int c1[26], c2[26];

inline void main2() {
  memset(c1, 0, sizeof c1);
  memset(c2, 0, sizeof c2);
  scanf(" %s %s", s1, s2);
  int l1 = strlen(s1), l2 = strlen(s2);
  for(int i = 0; i < l1; ++i) c1[s1[i] - 'a']++;
  for(int i = 0; i < l2; ++i) c2[s2[i] - 'a']++;
  ll ans = 0;
  for(int i = 0; i < 26; ++i) ans += abs(c1[i] - c2[i]);
  printf("%lld\n", ans);
}


int main() {
  int t; scanf("%d", &t);
  while(t--) main2(); 
  return 0;
}