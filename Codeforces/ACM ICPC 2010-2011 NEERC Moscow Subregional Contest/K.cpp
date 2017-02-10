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
#define pi acos(-1.0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 101010;

int pset[N];
int marc[N];

int fnd(int i) { return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
void uni(int i, int j) { pset[fnd(i)] = fnd(pset[j]); }
bool same(int i, int j) { return fnd(i) == fnd(j); }
void init(int _n) { for(int i = 0; i < _n; ++i) pset[i] = i; }

int n, k, l;

int main() {
  scanf("%d %d %d", &n, &k, &l);
  init(n);
  for(int i = 0; i < k; ++i){
    int x; scanf("%d", &x); x--;
    marc[x]++;
  }

  

  return 0;
}