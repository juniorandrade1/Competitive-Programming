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

const int N = 1010;

char s[N];
int pd[N][3];
int n;

int func(int pos, int qtd) {
  if(pos == n) return 0;
  if(pd[pos][qtd] != -1) return pd[pos][qtd];
  int ret = 1 + func(pos + 1, qtd);
  if(qtd == 0){
    if(s[pos] == '3') ret = min(ret, func(pos + 1, qtd));
    else ret = min(ret, func(pos + 1, 1));
  }
  else if(qtd == 1) if(s[pos] == '1') ret = min(ret, func(pos + 1, qtd));
  return pd[pos][qtd] = ret; 

}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf(" %s", s);
  n = strlen(s);
  memset(pd, -1, sizeof pd);
  printf("%d\n", func(0, 0));
  return 0;
}