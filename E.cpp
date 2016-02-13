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

const int N = 100000 * 34;

int tr[N][2];
int id[N * 2];
int cnt = 1;

void add(int x, int idx) {
  int cur = 0;
  for(int i = 32; i >= 0; --i) {
    bool ok = ((1LL<<(ll)i) & x);
    if(tr[cur][ok] == 0) tr[cur][ok] = cnt++;
    cur = tr[cur][ok];
  }
  if(id[cur] == 0) id[cur] = idx;
}

int query(int x) {
  int cur = 0;
  for(int i = 32; i >= 0; --i) {
    bool ok = ((1LL<<(ll)i) & x);
    if(tr[cur][!ok]) cur = tr[cur][!ok];
    else cur = tr[cur][ok];
  }
  return id[cur];
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    
    memset(tr, 0, sizeof tr);
    memset(id, 0, sizeof id);

    int n, q; scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) {
      int x; scanf("%d", &x);
      add(x, i);
    }
    while(q--){
      int x; scanf("%d",&x);
      printf("%d\n", query(x));
    }
    printf("\n");
  }
  return 0;
}
