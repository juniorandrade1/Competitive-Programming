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

int iWannaRand = 1;

int main() {
  int test = 100;
  printf("%d\n", test);
  while(test--) {
    int n = 2000;
    int m = 1000000000;
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; ++i) {
      if(iWannaRand == 0) printf("%d\n", 2000);
      else printf("%d\n", rand() % 2000 + 1);
    }
  } 

  return 0;
}