#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define EPS 1e-7
#define PI  3.1415926535897932384626433832795028841971693993
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 1011;

ll n;
double X[N], Y[N], Z[N];
int pset[N];
vector< pair<double, ii> > edge;

inline void init() { for(int i = 0; i < n; ++i) pset[i] = i; }
int fnd(int i){ return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
void uni(int i, int j){ pset[fnd(i)] = fnd(pset[j]); }

inline double quad(double x) {
  return x * x;
}

inline double getDist(int i, int j) {
  double x2 = quad(X[i] - X[j]);
  double y2 = quad(Y[i] - Y[j]);
  double z2 = quad(Z[i] - Z[j]);
  return sqrt(x2 + y2 + z2);
}

inline double go() {
  init();
  int q = n - 1;
  double sol = 0;
  for(int i = 0; i < edge.size() && q; ++i) {
    int x = edge[i].S.F, y = edge[i].S.S;
    if(fnd(x) != fnd(y)) {
      uni(x, y);
      sol = edge[i].F;
      q--;
    }
  }
  return sol;
}

int main() {
  //ios::sync_with_stdio(0);
  scanf("%lld", &n);
  for(int i = 0; i < n; ++i) scanf("%lf %lf %lf", X + i, Y + i, Z + i);
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) edge.pb(mp(getDist(i, j), ii(i, j)));
  sort(edge.begin(), edge.end());
  printf("%.10lf\n", go() * 0.5);
  return 0;
}