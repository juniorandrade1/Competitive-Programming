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
int acc[N];
int n;

bool ok() {
  int q = 0;
  for(int i = 0; i < 26; ++i) {
    q += (acc[i] > 0);
  }
  return q > n;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  scanf(" %s", s);
  int maxLen = 0;
  int la, ra;
  la = ra = 0;
  int l = 0;
  int lol = strlen(s);
  for(int r = 0; r < lol; ++r) {
    acc[s[r] - 'a']++;
    while(ok()) acc[s[l++] - 'a']--;
    if(r - l + 1 > maxLen) {
      maxLen = r - l + 1;
      la = l;
      ra = r;
    }
  }

  printf("%d %d\n", la + 1, ra + 1);
  return 0;
}