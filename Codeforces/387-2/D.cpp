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

const int N = 200010;

int n, k;
int a[N];

int main() {
  scanf("%d %d", &n, &k);
  int qtd = 0;
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    qtd += (a[i] < 0);
  }
  if(qtd == 0) {
    puts("0");
    exit(0);
  }
  if(qtd > k) {
    puts("-1");
    exit(0);
  }
  k -= qtd;
  int lst = 0;
  int changes = 0;
  int lol = 0;
  qtd = 0;
  vi oi;
  for(int i = 1; i <= n; ++i) {
    if(lst < 0 && a[i] >= 0) {
      changes++;
      qtd = 0;
    }
    else if(lst >= 0 && a[i] < 0) {
      changes++;
      if(lol) oi.pb(qtd);
      lol = 1;
      qtd = 0;
    }
    qtd++;
    lst = a[i];
  }
  
  vi app;
  if(lst >= 0) app.pb(qtd);

  sort(oi.begin(), oi.end());
  for(int i = 0; i < oi.size(); ++i) {
    if(oi[i] > k) break;
    changes -= 2;
    k -= oi[i];
  }
  sort(app.begin(), app.end());
  for(int i = 0; i < app.size(); ++i) {
    if(app[i] > k) break;
    changes--;
    k -= app[i];
  }
  printf("%d\n", changes);

  return 0;
}