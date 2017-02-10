#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 1001000;

int pset[N];
int n;

void init() { for(int i = 0; i <= n; ++i) pset[i] = i; }
int fnd(int i){ return (pset[i] == i ? i : (pset[i] = fnd(pset[i]))); }
void uni(int i, int j) { pset[fnd(i)] = fnd(pset[j]); }


int main() {
  scanf("%d", &n);
  init();
  for(int i = 1; i <= n; ++i) {
    int p; scanf("%d", &p);
    uni(p, i);
  }
  set<int>s; for(int i = 1; i <= n; ++i) s.insert(fnd(i));
  printf("%d\n", (int)s.size());
  return 0;
}