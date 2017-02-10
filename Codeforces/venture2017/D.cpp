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

const int N = 1000010;

int n, k;
vector< ii > pares;


int main() {
  scanf("%d %d", &n, &k);
  ll x = 1;
  ll lst = 1;
  int cnt = 0;
  while(1) {
    cnt++;
    ll prox = x + k;
    if(prox > n) prox -= n;
    ll sol = 1;
    int a1 = min(prox, x);
    int a2 = max(prox, x);

    vector< ii > :: iterator it1 = pares.begin();
    vector< ii > :: iterator it2 = pares.end();
    for(vector< ii > ::iterator it = it1; it != it2; it++) {
      sol += (it->F < a1 && a1 < it->S && (a2 < it->F || a2 > it->S));
      sol += (it->F < a2 && a2 < it->S && (a1 < it->F || a1 > it->S));
    }
    lst += sol;
    printf("%lld ", lst);

    pares.pb(mp(min((ll)x, (ll)prox), max((ll)x, (ll)prox)));
    x = prox;
    if(x == 1) break;
  } 
  printf("\n");
  return 0;
}