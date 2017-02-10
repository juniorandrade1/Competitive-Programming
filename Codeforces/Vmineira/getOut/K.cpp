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

double p[4][4][4][4];
int v[6];
int aD[6], bD[6];

void calc(int a, int d) {
  for(int i = 0; i < a; ++i) aD[i] = v[i];
  for(int i = 0; i < d; ++i) bD[i] = v[i + a];
  sort(aD, aD + a);
  reverse(aD, aD + a);
  sort(bD, bD + d);
  reverse(bD, bD + d);
  int ca, cb;
  ca = cb = 0;
  for(int i = 0; i < min(a, d); ++i) {
    if(aD[i] > bD[i]) cb++;
    else ca++;
  }
  p[a][d][ca][cb] += 1.0;
}

void generator(int a, int d, int id = 0) {
  if(id == a + d) {
    calc(a, d);
    return;
  }
  for(int i = 1; i <= 6; ++i) {
    v[id] = i;
    generator(a, d, id + 1);
  }
}

const int N = 10010;

double pd[4][N];

double func(int na, int nd) {
  for(int i = 0; i <= na; ++i) {
    for(int j = 0; j <= nd; ++j) {
      if(i == 0) pd[i & 3][j] = 0.0;
      else if(j == 0) pd[i & 3][j] = 1.0;
      else {
        int playA = min(i, 3);
        int playB = min(j, 3);
        int minK = min(playA, playB);
        pd[i & 3][j] = 0;
        for(int k = 0; k <= minK; ++k) pd[i & 3][j] += p[playA][playB][k][minK - k] * pd[(i - k) & 3][j - (minK - k)];
      }
    }
  }
  return pd[na & 3][nd];
}

int main() {
  for(int i = 1; i <= 3; ++i) for(int j = 1; j <= 3; ++j) generator(i, j);
  for(int i = 0; i <= 3; ++i) for(int j = 0; j <= 3; ++j) for(int k = 0; k <= 3; ++k) for(int l = 0; l <= 3; ++l) p[i][j][k][l] /= pow(6.0, i + j);
  int n, m; scanf("%d %d", &n, &m);
  printf("%.4lf\n", func(n - 1, m));
  return 0;
}