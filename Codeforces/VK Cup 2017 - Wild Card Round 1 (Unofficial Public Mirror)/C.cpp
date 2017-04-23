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

const int N = 100010;


int high[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int pd[N];

int func(int x) {
  if(x == 0) return pd[x] = 0;
  if(pd[x] != -1) return pd[x];
  pd[x] = 0;
  for(int i = 9; i >= 0; --i) if(high[i] <= x) pd[x] = max(pd[x], 1 + func(x - high[i]));
  return pd[x];
}

void back(int x) {
  if(x == 0) return;
  if(pd[x] == 0) return;
  for(int i = 9; i >= 0; --i) {
    if(high[i] <= x && 1 + func(x - high[i]) == pd[x]) {
      printf("%d", i);
      back(x - high[i]);
      return;
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  memset(pd, -1, sizeof pd);
  int ans = func(n);
  back(n);
  printf("\n");
  return 0;
}