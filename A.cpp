#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

double pd[1<<20];
double mat[20][20];

void main2() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%lf", &mat[i][j]);
  for(int i = 0; i < (1 << n); ++i) pd[i] = 0.;
  pd[(1 << n) - 1] = 1.;
  for(int i = (1 << n) - 1; i >= 0; --i) {
    ll b = __builtin_popcount(i);
    double den = 2. / (double)(b * (b - 1LL));
    for(int j = 0; j < n; ++j) {
      for(int k = j + 1; k < n; ++k) {
        if( ((1 << j) & i) && ((1 << k) & i) ) {
          pd[i ^ (1 << k)] += pd[i] * den * mat[j][k];
          pd[i ^ (1 << j)] += pd[i] * den * mat[k][j];
        }
      }
    }
  }
  for(int i = 0; i < n; ++i) printf(" %.6lf", pd[1 << i]);
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    printf("Case %d:", i);
    main2();
    printf("\n");
  }
  return 0;
}
