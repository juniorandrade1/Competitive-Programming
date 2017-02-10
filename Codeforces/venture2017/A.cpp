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

bool isPrime(int x) {
  for(int i = 2; i * i <= x; ++i) if(x % i == 0) return false;
  return true;
}

int main() {
  int n; scanf("%d", &n);
  for(int m = 1;; ++m) {
    if(isPrime(n * m + 1)) continue;
    printf("%d\n", m);
    return 0;
  }
  return 0;
}