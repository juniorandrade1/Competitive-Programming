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
string b = "Bulbasaur";
map<char, int> qtd;

int main() {
  scanf(" %s", s);
  int len = strlen(s);
  for(int i = 0; i < len; ++i) qtd[s[i]]++;
  int maxi = INF;
  maxi = min(maxi, qtd['B']);
  maxi = min(maxi, qtd['u'] / 2);
  maxi = min(maxi, qtd['l']);
  maxi = min(maxi, qtd['b']);
  maxi = min(maxi, qtd['a'] / 2);
  maxi = min(maxi, qtd['r']);
  printf("%d\n", maxi);
  return 0;
}