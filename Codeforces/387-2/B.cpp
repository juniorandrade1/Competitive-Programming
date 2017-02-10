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

char s[12345];
int n;
int cnt[26];

char o[] = {'A', 'C', 'T', 'G'};

int main() {
  scanf("%d", &n);
  scanf(" %s", s);
  if(n % 4) {
    puts("===");
    exit(0);
  }
  int need = n / 4;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '?') continue;
    cnt[s[i] - 'A']++;
    if(cnt[s[i] - 'A'] > need) {
      puts("===");
      exit(0);
    }
  }

  int op = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '?') {
      while(cnt[o[op] - 'A'] >= need) op++;
      s[i] = o[op];
      cnt[o[op] - 'A']++;
    }
  }
  printf("%s\n", s);
  return 0;
}