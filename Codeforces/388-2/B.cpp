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

int X[3], Y[3];
double dx, dy;
double nx, ny;
double ox, oy;


int main() {
  for(int i = 0; i < 3; ++i) {
    scanf("%d %d", X + i, Y + i);
  }

  set< ii > p;

  dx = X[1] - X[0]; dy = Y[1] - Y[0];
  dx *= 0.5; dy *= 0.5;
  nx = X[0] + dx; ny = Y[0] + dy;
  dx = nx - X[2]; dy = ny - Y[2];
  ox = X[2] + 2 * dx; oy = Y[2] + 2 * dy;
  if(fabs(ox - round(ox) < 1e-6 && fabs(oy - round(oy) < 1e-6))) p.insert(ii(round(ox), round(oy)));

  dx = X[2] - X[0]; dy = Y[2] - Y[0];
  dx *= 0.5; dy *= 0.5;
  nx = X[0] + dx; ny = Y[0] + dy;
  dx = nx - X[1]; dy = ny - Y[1];
  ox = X[1] + 2 * dx; oy = Y[1] + 2 * dy;
  if(fabs(ox - round(ox) < 1e-6 && fabs(oy - round(oy) < 1e-6))) p.insert(ii(round(ox), round(oy)));

  dx = X[2] - X[1]; dy = Y[2] - Y[1];
  dx *= 0.5; dy *= 0.5;
  nx = X[1] + dx; ny = Y[1] + dy;
  dx = nx - X[0]; dy = ny - Y[0];
  ox = X[0] + 2 * dx; oy = Y[0] + 2 * dy;
  if(fabs(ox - round(ox) < 1e-6 && fabs(oy - round(oy) < 1e-6))) p.insert(ii(round(ox), round(oy)));




  printf("%d\n", (int)p.size());
  for(set<ii>::iterator it = p.begin(); it != p.end(); it++) {
    printf("%lld %lld\n", it->F, it->S);
  }
  return 0;
}