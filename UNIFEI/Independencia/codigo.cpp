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

#define pi acos(-1.0)

const int N = 123456;

char s[N];
char title[N];
int cod[256];

string bad = "AEIOUYWH";

bool isBad(char c) {
  for(int i = 0; i < bad.size(); ++i) {
    if(c == bad[i]) return true;
  }
  return false;
}

int main() {
  cod['B'] = cod['P'] = cod['F'] = cod['V'] = 1;
  cod['C'] = cod['S'] = cod['X'] = cod['Z'] = 2;
  cod['K'] = cod['G'] = cod['J'] = cod['Q'] = 3;
  cod['D'] = cod['T'] = 4;
  cod['L'] = 5;
  cod['M'] = cod['N'] = 6;
  cod['R'] = 7;

  for(int i = 0; i < 9; ++i) printf(" ");
  printf("NOME");
  for(int i = 0; i < 35 - 14; ++i) printf(" ");
  printf("CODIGO LOUCO DO ROBERTO\n");
  printf("---------------------------------------------------------\n");
  while(scanf(" %s", s) != EOF) {
    int len = strlen(s);

    string sol = "";
    sol.pb(s[0]);
    int sz = 1;
    for(int i = 1; i + 1 < len; ++i) {
      if(isBad(s[i])) continue;
      if(cod[s[i - 1]] == cod[s[i]]) continue;
      sol.pb(cod[s[i]] + '0');
      sz++;
    }
    while(sol.size() + 1 < len) sol.pb('0');
    sol.pb(s[len - 1]);

    for(int i = 0; i < 9; ++i) printf(" ");
    printf("%s", s);
    for(int i = 0; i < 35 - (10 + len); ++i) printf(" ");
    printf("%s\n", sol.c_str());
  }
  for(int i = 0; i < 19; ++i) printf(" ");
  printf("FIM DO PROGRAMA\n");
  return 0;
}